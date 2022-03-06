#include <Arduino.h>
#include "IRsend.h"
#include <IRremoteESP8266.h>



#define IRLED 12

IRsend irsend(IRLED);

void setup() {
    irsend.begin();
}

void loop() {
    irsend.sendNEC(0xF00F55AA, 32);
    delay(500);
}