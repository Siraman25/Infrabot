#include <Arduino.h>
#include<Servo.h>

#define BUTTON 10
#define BUTTON2 11
Servo MotorLeft; 
Servo MotorRight;
bool button = 0;
bool button2 = 0;
int pos = 0;
int pos2 = 0;

void setup()
{
    MotorLeft.attach(9);
    MotorRight.attach(5);
    pinMode(BUTTON, INPUT);
    pinMode(BUTTON2, INPUT);
}

void loop()
{

button = digitalRead(BUTTON);
button2 = digitalRead(BUTTON2);
    /*  //Vorwertsbewegen
    if (button == HIGH)
    {
        for (pos = 0; pos <= 180; pos += 1)
        {                         // goes from 0 degrees to 180 degrees
            MotorLeft.write(pos); // tell servo to go to position in variable 'pos'
            MotorRight.write(pos);
                delay(15); // waits 15 ms for the servo to reach the position
        }
    }

    //Rückwertsbewegen
    if(button == LOW)
    {
    for (pos = 180; pos >= 0; pos -= 1)
        {                         // goes from 180 degrees to 0 degrees
            MotorLeft.write(pos); // tell servo to go to position in variable 'pos'
            MotorRight.write(pos);
            delay(15);            // waits 15 ms for the servo to reach the position
        }
    }*/
    //nach links
    if(button2 == HIGH)
    {
       for (pos = 180; pos >= 0; pos -= 1)
        { 
            
            pos2 ++;
            MotorLeft.write(pos2);
            MotorRight.write(pos);
            delay(15);            
        }
    }
    if(button2 == LOW)
    {
        pos2 = 180;
        for (pos = 0; pos >= 180; pos += 1)
        { 
            
            pos2 = pos2 -1;
            MotorLeft.write(pos2);
            MotorRight.write(pos);
            delay(15);            
        }
    }
}