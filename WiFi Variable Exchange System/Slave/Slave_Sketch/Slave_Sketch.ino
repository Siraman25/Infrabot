// Slave-Sketch

#define LED 10
#define SERVER_PORT 45550

#include <WiFi.h>

const char* ssid = "Danladman";
const char* password = "lol123456";

IPAddress ip(192, 168, 1, 111);
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

IPAddress master(192, 168, 1, 110);

WiFiServer SlaveServer(SERVER_PORT);
WiFiClient SlaveClient = SlaveServer.available();

void connectToWireless() {
  while (WiFi.status() != WL_CONNECTED) {
   delay(500);
   Serial.print(F("."));
 }
 Serial.println("System online.");
 Serial.println(WiFi.localIP());
}

void setup() {
  delay(1000);
  pinMode(LED, OUTPUT);
  Serial.begin(115200);
  Serial.println("System initialized.");
  
  WiFi.config(ip, gateway, subnet); // Static IP setup
  WiFi.begin(ssid, password);
  connectToWireless();

  SlaveServer.begin();
}

int currentResult;

void loop() {
  WiFiClient Client = SlaveServer.available();

  if (Client) {
    // Read the command from the TCP client:
    //char command = client1.read();
    //Serial.print("Received command: ");
    //Serial.println(command);
    char command = Client.read();
    currentResult = command;
    if (currentResult != 255) {
      Serial.println(currentResult);
    }
  }
}
