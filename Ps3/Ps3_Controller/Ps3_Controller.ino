#include <dummy.h>
#include <Ps3Controller.h>

int lX = 0;
int rX = 0;
int posR = 0;
void onConnect()
{
 Serial.println("IsConnected");
}
void notify(){
   lX =(Ps3.data.analog.stick.lx);
   rX =(Ps3.data.analog.stick.rx);


   if(lX < -5 && posR < 180)
 {
  posR++;
  Serial.println(posR);
  delay(10);
 }
              //cross right side
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
  
}

void setup() {
  
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
