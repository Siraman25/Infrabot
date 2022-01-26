#include <Servo.h>
#include <Ps3Controller.h>

int lX = 0;
int lY = 0;
int rX = 0;
int rY = 0;
#define LEDROT 13
int gesch = 0;
int posR = 0;
int L1 = 0;
int L2 = 0;
int R1 = 0;
int R2 = 0;

int ServoMerker = 0;
int ServoMerker1 = 0;
static const int servosPins[2] = {33, 13};
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
   }

   if( abs(Ps3.event.analog_changed.button.r2) ){
       Serial.print("Pressing the right trigger button: ");
     
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
    servos[0].write(0);
    servos[1].write(0);
      }
        else if(Ps3.data.analog.stick.lx == 127){         //robo nach rechts
         Serial.println("nach rechts" + lX);
         
          servos[0].write(180);
          servos[1].write(180); 
            } 
        else if(Ps3.data.analog.stick.ly == -128){         //robo nach vorne                  
        //Serial.println("nach vorne" + lY); 
    servos[0].write(0);
    servos[1].write(180);
            } 
        else if(Ps3.data.analog.stick.ly >= 127){           //robo nach hinten
          Serial.println("nach hinten" + lY);  
          
          servos[0].write(180);
          servos[1].write(0);  
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
