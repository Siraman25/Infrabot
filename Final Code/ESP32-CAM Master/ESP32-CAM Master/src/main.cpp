#include <Arduino.h>
#include "esp_camera.h"
#include <WiFi.h>
#include <Ps3Controller.h>
#include <ESP32Servo.h>

#include "soc/soc.h"
#include "soc/rtc_cntl_reg.h"

#define MYPORT_TX 13
#define MYPORT_RX 14

#define stopSendTimeout 1
#define resetSendTimeout 5000

#define CAMERA_MODEL_AI_THINKER // Has PSRAM

#include "camera_pins.h"

const char *ssid = "Danladman";
const char *password = "lol123456";
IPAddress staticIP(192, 168, 1, 110);     // Master ESP32-CAM: 110
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

static const int servosPins[2] = {12, 2};
Servo servos[2];

void startCameraServer();

void onConnect();

void checkPS3Controller();

bool lockIRSender = false;                  // Lock for bluetooth-controlled shooting action
unsigned long infraRedSendTimestamp = 0;    // Timestamp for IR-lock

void setup() {
    delay(500);
    WRITE_PERI_REG(RTC_CNTL_BROWN_OUT_REG, 0);          // Disable brownout detector !! WARNING !!
    Serial.begin(115200);
    Serial.setDebugOutput(true);
    Serial.println();

    Serial2.begin(9600, SERIAL_8N1, MYPORT_RX, MYPORT_TX);

    Ps3.attachOnConnect(onConnect);
    Ps3.begin("00:13:a9:e0:cd:a9");

    camera_config_t config;
    config.ledc_channel = LEDC_CHANNEL_3;
    config.ledc_timer = LEDC_TIMER_1;
    config.pin_d0 = Y2_GPIO_NUM;
    config.pin_d1 = Y3_GPIO_NUM;
    config.pin_d2 = Y4_GPIO_NUM;
    config.pin_d3 = Y5_GPIO_NUM;
    config.pin_d4 = Y6_GPIO_NUM;
    config.pin_d5 = Y7_GPIO_NUM;
    config.pin_d6 = Y8_GPIO_NUM;
    config.pin_d7 = Y9_GPIO_NUM;
    config.pin_xclk = XCLK_GPIO_NUM;
    config.pin_pclk = PCLK_GPIO_NUM;
    config.pin_vsync = VSYNC_GPIO_NUM;
    config.pin_href = HREF_GPIO_NUM;
    config.pin_sscb_sda = SIOD_GPIO_NUM;
    config.pin_sscb_scl = SIOC_GPIO_NUM;
    config.pin_pwdn = PWDN_GPIO_NUM;
    config.pin_reset = RESET_GPIO_NUM;
    config.xclk_freq_hz = 20000000;
    config.pixel_format = PIXFORMAT_JPEG;

    // if PSRAM IC present, init with UXGA resolution and higher JPEG quality
    //                      for larger pre-allocated frame buffer.
    if (psramFound()) {
        config.frame_size = FRAMESIZE_UXGA;
        config.jpeg_quality = 10;
        config.fb_count = 2;
    } else {
        config.frame_size = FRAMESIZE_SVGA;
        config.jpeg_quality = 12;
        config.fb_count = 1;
    }

    // camera init
    esp_err_t err = esp_camera_init(&config);
    if (err != ESP_OK) {
        Serial.printf("Camera init failed with error 0x%x", err);
        return;
    }

    sensor_t *s = esp_camera_sensor_get();
    // initial sensors are flipped vertically and colors are a bit saturated
    if (s->id.PID == OV3660_PID) {
        s->set_vflip(s, 1); // flip it back
        s->set_brightness(s, 1); // up the brightness just a bit
        s->set_saturation(s, -2); // lower the saturation
    }
    // drop down frame size for higher initial frame rate
    s->set_framesize(s, FRAMESIZE_QVGA);

    WiFi.config(staticIP, gateway, subnet);
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("");
    Serial.println("WiFi connected");

    startCameraServer();

    Serial.print("Camera Ready! Use 'http://");
    Serial.print(WiFi.localIP());
    Serial.println("' to connect");

    for(int i = 0; i < 2; ++i) {
        if (!servos[i].attach(servosPins[i])) {
            Serial.print("Servo ");
            Serial.print(i);
            Serial.println("attach error");
        }
    }
}

void loop() {
    checkPS3Controller();

    if (lockIRSender) {
        if ((millis() - infraRedSendTimestamp) >= resetSendTimeout) {
            lockIRSender = false;
        }
        if ((millis() - infraRedSendTimestamp) < stopSendTimeout) {
            Serial2.write('y');
        }
    }
}

void checkPS3Controller() {
    if(Ps3.data.analog.stick.lx == -128){                       //robo nach links
        // Serial.println("nach links" + lX);
        servos[0].write(0);
        servos[1].write(0);
    }
    else if(Ps3.data.analog.stick.lx == 127){         //robo nach rechts
        // Serial.println("nach rechts" + lX);

        servos[0].write(180);
        servos[1].write(180);
    }
    else if(Ps3.data.analog.stick.ly == -128){         //robo nach vorne
        // Serial.println("nach vorne" + lY);
        servos[0].write(0);
        servos[1].write(180);
    }
    else if(Ps3.data.analog.stick.ly >= 127){           //robo nach hinten
        // Serial.println("nach hinten" + lY);

        servos[0].write(180);
        servos[1].write(0);
    }
    else
    {
        servos[0].write(90);
        servos[1].write(90);
    }
//    if (Ps3.event.analog_changed.button.r2 || Ps3.event.analog_changed.button.l2) {
//        Serial2.write('y');
//    }

    if (!lockIRSender) {  // TODO: Lock IRremote and send to LED
        if (Ps3.event.analog_changed.button.r2 || Ps3.event.analog_changed.button.l2) {
            lockIRSender = true;
            infraRedSendTimestamp = millis();
        }
    }
}

void onConnect() {
    Serial.println("Successfully connected PS3 controller.");
}