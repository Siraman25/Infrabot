#include <Servo.h>

int ServoMerker = 0;
int ServoMerker1 = 0;
static const int servosPins[2] = {12, 14};

Servo servos[2];


void setup() {
    Serial.begin(115200);
    Serial.println("Start here");

    for(int i = 0; i < 2; ++i) {
      Serial.println("For loop");
        if(!servos[i].attach(servosPins[i])) {
            Serial.print("Servo ");
            Serial.print(i);
            Serial.println("attach error");}}
  Serial.println("StartServo");
  
  ServoMerker--;
  servos[1].write(90);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
   ServoMerker--;
    Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  ServoMerker--;
   Serial.println("1");
  servos[1].write(ServoMerker);
  Serial.println("1");
 
        }


void loop() {
 
/*
  ServoMerker++;
  ServoMerker1++;
  servos[0].write(ServoMerker1);
  servos[1].write(ServoMerker);
    delay(290);
  /*
    for(int posDegrees = 0; posDegrees <= 180; posDegrees++) {
        setServos(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }

    for(int posDegrees = 180; posDegrees >= 0; posDegrees--) {
        setServos(posDegrees);
        Serial.println(posDegrees);
        delay(20);
    }*/
}
