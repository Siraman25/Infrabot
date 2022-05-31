#include <Arduino.h>
#include <Ps3Controller.h>
#include "IRsend.h"

#include "soc/timer_group_struct.h"         // Watchdog protection
#include "soc/timer_group_reg.h"            // Watchdog protection

#define PTS_RST_PIN 2                       // Reset score button
#define IRLED 12

#define stopSendTimeout 2000
#define resetSendTimeout 5000

TaskHandle_t Core0;
TaskHandle_t Core1;
IRsend InfraredLED(IRLED);

[[noreturn]] void TaskCore0(void *pvParams);        // Definition of Core0 function
[[noreturn]] void TaskCore1(void *pvParams);        // Definition of Core1 function
void checkResetButton();                            // Definition of reset button check function
void onConnect();                                   // Definition of connect function (PS3-controller)
void checkPS3Controller();                         // Definition of PS3-controller check function

void setup() {
    Serial.begin(115200);
    xTaskCreatePinnedToCore(TaskCore0, "Core0", 10000, nullptr, 1, &Core0, 0);
    delay(200);
    //xTaskCreatePinnedToCore(TaskCore1, "Core1", 10000, nullptr, 1, &Core1, 1);
    delay(200);
    pinMode(PTS_RST_PIN, INPUT);
    InfraredLED.begin();
}

int pointsMaster = 0;                       // Point counting system
int pointsSlave = 0;                        // Point counting system

bool previousButtonState = false;           // Reset button
bool currentButtonState = false;            // Reset button
unsigned long resetButtonTimestamp = 0;     // Reset button

bool lockIRSender = false;                  // Lock for bluetooth-controlled shooting action
unsigned long infraRedSendTimestamp = 0;    // Timestamp for IR-lock

static const int servosPins[2] = {14, 15};


[[noreturn]] void TaskCore0(void *pvParams) {
    Serial.println();
    Serial.print("Task on core: ");
    Serial.println(xPortGetCoreID());

    Ps3.begin("00:13:a9:e0:cd:a9");
    Ps3.attachOnConnect(onConnect);

    for(;;){           // New loop function for core 0
        TIMERG0.wdt_wprotect=TIMG_WDT_WKEY_VALUE;       // Following 3 lines are needed to protect from watchdog
        TIMERG0.wdt_feed=1;
        TIMERG0.wdt_wprotect=0;

        checkResetButton();

        checkPS3Controller();
        //Serial.println("Main");
//        Serial.print(millis());
//        Serial.print(" - ");
//        Serial.println(infraRedSendTimestamp);

        //ESP32PWM().ChannelUsed[1];  // TODO: ???
        if (lockIRSender) {
            if ((millis() - infraRedSendTimestamp) >= resetSendTimeout) {
                Serial.println("stop");
                lockIRSender = false;

            }
            if ((millis() - infraRedSendTimestamp) < stopSendTimeout) {
                Serial.println("send");
                InfraredLED.sendNEC(0xF00F55AA, 32);
                delay(10);
                InfraredLED.sendNEC(0xF00F55AA, 32);
                delay(10);
                InfraredLED.sendNEC(0xF00F55AA, 32);
                delay(10);
                InfraredLED.sendNEC(0xF00F55AA, 32);
                delay(10);
            }
        }

        pointsMaster++;
        // Serial.println(pointsMaster);
    }
}

[[noreturn]] void TaskCore1(void *pvParams) {
    Serial.println();
    Serial.print("Task on core: ");
    Serial.println(xPortGetCoreID());
    for(;;){           // New loop function for core 1
        delay(1000);
    }
}

void checkResetButton() {                                           // Checks reset score button and proceeds with reset
    previousButtonState = currentButtonState;
    currentButtonState = digitalRead(PTS_RST_PIN);
    if (currentButtonState == 1 && previousButtonState == 0) {
        if (millis() - resetButtonTimestamp >= 100) {
            Serial.println(pointsMaster);
            pointsMaster = 0;
            Serial.println(pointsMaster);
        }
        resetButtonTimestamp = millis();
    }
}

void checkPS3Controller() {                                        // Checks PS3 controller and updates servos
    
}

void onConnect() {
    Serial.println("Successfully connected PS3 controller.");
}

void loop() {
    delay(1000);        // Core1-Loop gets bypassed with delay. TaskCore1 gets prioritized.
}
