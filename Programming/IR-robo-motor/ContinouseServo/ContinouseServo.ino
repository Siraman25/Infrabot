#include <Servo.h>

int ServoMerker = 0;
int ServoMerker1 = 0;
static const int servosPins[2] = {12, 14};

Servo servos[2];


void setup() {
    Serial.begin(115200);

    for(int i = 0; i < 2; ++i) {
        if(!servos[i].attach(servosPins[i])) {
            Serial.print("Servo ");
            Serial.print(i);
            Serial.println("attach error");
        }
    }
}

void loop() {
  ServoMerker--;
  ServoMerker1--;
  servos[0].write(ServoMerker1);
  servos[1].write(ServoMerker);
  delay(290);

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
