#include <Arduino.h>
void setup() {
    pinMode(4, OUTPUT);
}

void loop() {
    digitalWrite(4, HIGH);
    delay(100);
    digitalWrite(4, LOW);
    delay(1000);
}