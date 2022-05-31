#include <Servo.h>
#include <Ps3Controller.h>

int lX = 0;
int lY = 0;
int rX = 0;
int rY = 0;
#define LEDROT 14
int gesch = 0;
int posR = 0;
int L1 = 0;
int L2 = 0;
int R1 = 0;
int R2 = 0;

int ServoMerker = 0;
int ServoMerker1 = 0;
static const int servosPins[2] = {12, 13};
Servo servos[2];

void onConnect()
{
 Serial.println("IsConnected");
}

void notify(){
  Serial.println("Mainloop repeat");
 //***************************L2 & R2***************************************************?

    if( abs(Ps3.event.analog_changed.button.l1)){
       Serial.print("Pressing the left shoulder button: ");
    }

   if( 100 < abs(Ps3.event.analog_changed.button.r1) ){
       Serial.print("Pressing the right shoulder button: ");
   }

   if( abs(Ps3.event.analog_changed.button.l2) ){
       Serial.print("Pressing the left trigger button: ");
       Serial.println(Ps3.data.analog.button.l2, DEC);
   }

   if( abs(Ps3.event.analog_changed.button.r2) ){
       Serial.print("Pressing the right trigger button: ");
       Serial.println(Ps3.data.analog.button.r2, DEC);
       
            digitalWrite(LEDROT,HIGH);
   }
           else
        {
          digitalWrite(LEDROT,LOW);
        }  
  
//****************************right stick************************************************
/*
   rX =(Ps3.data.analog.stick.rx);
   rY = (Ps3.data.analog.stick.ry);
   
if(rX == -128){                       //robo nach links
  Serial.println("nach links");
      }
if(rX == 127){
    Serial.println("nach rechts");    
      } 
 if(rY == -128){                       //robo nach links
  Serial.println("nach vorne");
      }
if(rY == 127){
    Serial.println("nach hinten");    
      } 
      */
 //****************************left stick***********************************************?

Serial.println(Ps3.data.analog.stick.lx);
Serial.println(Ps3.data.analog.stick.ly);

if(Ps3.data.analog.stick.lx == -128){                       //robo nach links
  Serial.println("nach links" + lX);
  gesch = 0,7*Ps3.data.analog.stick.lx + 90;
    servos[0].write(gesch);
    servos[1].write(gesch);
      }
        else if(Ps3.data.analog.stick.lx == 127){         //robo nach rechts
         Serial.println("nach rechts" + lX);
         gesch = 0,7 * Ps3.data.analog.stick.lx + 90;
          servos[0].write(gesch);
          servos[1].write(gesch); 
            } 
        else if(Ps3.data.analog.stick.ly == -128){         //robo nach vorne                  
        Serial.println("nach vorne" + lY); 
        gesch = 0,7 * Ps3.data.analog.stick.ly + 90;
    servos[0].write(gesch);
    servos[1].write(gesch);
            } 
        else if(Ps3.data.analog.stick.ly >= 127){           //robo nach hinten
          Serial.println("nach hinten" + lY); 
          gesch = 0,7 * Ps3.data.analog.stick.ly + 90;
          
          servos[0].write(gesch);
          servos[1].write(gesch);  
            }
        else
            {
            servos[0].write(90);
            servos[1].write(90);  
            }
          
     
//****************************cross right side*******************************************
if( Ps3.data.button.cross ){
            Serial.println("Pressing the cross button");      //Pressing the cross button(X)
        }


if( Ps3.data.button.square ){
            Serial.println("Pressing the square button");     //Pressing the square button([])
        }

if( Ps3.data.button.triangle ){
            Serial.println("Pressing the triangle button");   //Pressing the triangle button
        }

if( Ps3.data.button.circle ){
            Serial.println("Pressing the circle button");     //Pressing the circle button
        }
  //****************************cross right side*******************************************?

  
}

void setup() {
  //******************************servo***************************
pinMode(LEDROT, OUTPUT);
for(int i = 0; i < 2; ++i) {
        if(!servos[i].attach(servosPins[i])) {
        Serial.print("Servo ");
        Serial.print(i);
        Serial.println("attach error");
        }
    }
    Serial.begin(115200);
    Ps3.begin("00:13:a9:e0:cd:a9");
    Ps3.attachOnConnect(onConnect);
    
    
    Ps3.attach(notify);
      
    
    
    Serial.println("Ready.");


}

void loop() 
{
  
if(Ps3.isConnected()){
            return;
            delay(1000);
         }

}
