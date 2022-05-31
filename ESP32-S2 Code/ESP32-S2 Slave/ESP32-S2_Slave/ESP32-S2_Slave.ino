#include <IRsend.h>
#include <WiFi.h>
#include <WebServer.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

#define DECODE_NEC

#define MYPORT_TX 42
#define MYPORT_RX 41

#define IRLED 40
#define IRREC 39
#define BUTTONRESET 38

#define stopSendTimeout 2000
#define resetSendTimeout 5000

#define IRsendTime 1000
#define dataUpdateTime 500

const char* ssid = "Danladman";
const char* password = "lol123456";
IPAddress staticIP(192, 168, 1, 211);     // Slave ESP32-S2: 211
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

const char* host = "192.168.1.210";       // Master ESP32-S2: 210

WebServer varsExchange;
WiFiClient client;

bool buttonInputValue = 0;
String header;

int masterPoints = 0;
int slavePoints = 0;

bool lockIRSender = false;                  // Lock for bluetooth-controlled shooting action
unsigned long infraRedSendTimestamp = 0;    // Timestamp for IR-lock

IRsend InfraredLED(IRLED);

IRrecv irrecv(IRREC);

decode_results results;

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, MYPORT_RX, MYPORT_TX);
  Serial.println("Start");
  InfraredLED.begin();

  WiFi.config(staticIP, gateway, subnet);
  WiFi.begin(ssid, password);
  Serial.print("Connecting to WiFi ..");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(100);
  }
  Serial.println(WiFi.localIP());
  varsExchange.on("/", handleSend);
  varsExchange.begin();

  irrecv.enableIRIn();
  pinMode(BUTTONRESET, INPUT);
}

char inByte = '0';

//void loop(){
//  InfraredLED.sendNEC(0xF00F55AA, 32);
//  delay(50);
//}

bool IRrecFlag = false;
unsigned long IRrecTimestamp = 0;
unsigned long dataUpdateTimestamp = 0;

void loop() {
  varsExchange.handleClient();
  if (lockIRSender) {
    if ((millis() - infraRedSendTimestamp) >= resetSendTimeout) {
      lockIRSender = false;
    }
    if ((millis() - infraRedSendTimestamp) < stopSendTimeout) {
      InfraredLED.sendNEC(0xF00F55AB, 32);      // AB -> 171
    }
  }


  if (Serial1.available() > 0) {
    Serial.println(Serial1.available());
    inByte = Serial1.read();
    Serial.println(inByte);
    if (!lockIRSender) {  // TODO: Lock IRremote and send to LED
      if (inByte == 'y') {
        lockIRSender = true;
        infraRedSendTimestamp = millis();
      } else if (inByte == 'x') {
        slavePoints++;
      }
    }
  }
  if (!IRrecFlag) {
    if (irrecv.decode(&results)) {
      // print() & println() can't handle printing long longs. (uint64_t)
      serialPrintUint64(results.value, HEX);
      Serial.println("");
      irrecv.resume();  // Receive the next value
      if (results.value == 170) {
        IRrecFlag = true;
        IRrecTimestamp = millis();
      }
    }
  }
  if (IRrecFlag) {
    if (millis() - IRrecTimestamp > IRsendTime) {
      IRrecFlag = false;
    }
  }

  if (millis() - dataUpdateTimestamp > dataUpdateTime) {
    if(client.connect(host,80)) {
    String url = "/";
    client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host +  "\r\n" + 
                 "Connection: keep-alive\r\n\r\n"); // minimum set of required URL headers
    delay(10);
    // Read all the lines of the response and print them to Serial
    Serial.println("Response: ");
    while(client.available()){
      String line = client.readStringUntil('\r');
      Serial.print(line);

      masterPoints = line.toInt();
      }
    }
  }

  buttonInputValue = digitalRead(BUTTONRESET);
  if (buttonInputValue) {
    slavePoints = 0;
  }
}

void handleSend() {
  varsExchange.send(200, "text/plain", String(slavePoints));
}
