#include <IRsend.h>

#define MYPORT_TX 42
#define MYPORT_RX 41

#define IRLED 12

#define stopSendTimeout 2000
#define resetSendTimeout 5000

bool lockIRSender = false;                  // Lock for bluetooth-controlled shooting action
unsigned long infraRedSendTimestamp = 0;    // Timestamp for IR-lock

IRsend InfraredLED(IRLED);

void setup() {
  Serial.begin(115200);
  Serial1.begin(9600, SERIAL_8N1, MYPORT_RX, MYPORT_TX);
  Serial.println("Start");
  InfraredLED.begin();
}

char inByte = '0';

void loop() {
  if (lockIRSender) {
        if ((millis() - infraRedSendTimestamp) >= resetSendTimeout) {
            lockIRSender = false;
        }
        if ((millis() - infraRedSendTimestamp) < stopSendTimeout) {
            InfraredLED.sendNEC(0xF00F55AA, 32);
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
        }
    }
  }
}
