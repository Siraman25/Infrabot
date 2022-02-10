// Master-Sketch

#define SERVER_PORT 45550

#include <WiFi.h>

const char* ssid = "Danladman";
const char* password = "lol123456";

IPAddress ip(192, 168, 1, 110);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

IPAddress slave(192, 168, 1, 111);

WiFiServer MasterServer(SERVER_PORT); // PORT IS NEEDED!! (With syntax: WiFiServer MasterServer(PORT))
WiFiClient MasterClient = MasterServer.available();

void connectToWireless() {
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(F("."));
 }
 Serial.println("System online.");
 Serial.println(WiFi.localIP());
}

//void connectToMasterClient() {
//  while (MasterClient.status()) {
//    delay(500);
//    Serial.print(F("-"));
//  }
//  Serial.println("Server connected.");
//}

void setup() {
  delay(1000);
  Serial.begin(115200);
  Serial.println("System initialized.");
  
  WiFi.config(ip, gateway, subnet); // Static IP setup
  WiFi.begin(ssid, password);
  connectToWireless();

  if (MasterClient.connect(slave, SERVER_PORT)) {
    Serial.println("Connected to TCP server");
  } else {
    Serial.println("Failed to connect to TCP server");
  }
}
int currentResult = 13;
char  currentResultInChar;

void loop() {
    delay(1000);
//    if (!MasterClient.connected()) {
//    Serial.println("Connection is disconnected");
//    MasterClient.stop();
//
//    // reconnect to TCP server
//    if (MasterClient.connect(slave, SERVER_PORT)){
//      Serial.println("Reconnected to TCP server");
//    }else{
//      Serial.println("Failed to reconnect to TCP server");
//    }
//  }

  if (Serial.available() > 0) {
    currentResult = Serial.readString().toInt();
  }

  
  currentResultInChar = currentResult;
  MasterClient.write(currentResultInChar);
//    Serial.write(wifi.read()); //this will print all inc data to your arduino console (serial) parse this data!

}
