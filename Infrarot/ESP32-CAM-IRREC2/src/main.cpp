#include <Arduino.h>
#include <IRremoteESP8266.h>
#include <IRrecv.h>
#include <IRutils.h>

const uint16_t kRecvPin = 15;

IRrecv irrecv(kRecvPin);

decode_results results;

void setup() {
    Serial.begin(115200);
    irrecv.enableIRIn();
}

void loop() {
    if (irrecv.decodeNEC(&results)) {
        // print() & println() can't handle printing long longs. (uint64_t)
        serialPrintUint64(results.value, HEX);
        Serial.println("");
        irrecv.resume();  // Receive the next value
    }
    delay(100);
}