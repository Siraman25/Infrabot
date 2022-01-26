# **Infrarot-Roboter**
## **Beschreibung**
Bei diesen Inrarot-Robotern handelt es sich um zwei auf Rädern fahrenden Robotern welche als "Shooter-Spiel" konzipiert sind. Sie werden über zwei ESP-32 gesteuert (ESP32-CAM & ESP32-S2). Bedient werden sie entweder mit einem PS3-Controller oder über eine Website via PC oder Smartphone. Die Steuerung über PS3-Controller wird durch eine Bluetooth-Verbindung zwischen Controller und ESP32-S2 realisiert.
![Connection_PS3_ESP32.png](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Readme/Connection_PS3_ESP32.png?raw=true)\
Sie können sich gegenseitig abschießen. Dies wird mit Infrarot-Empfänger und -Sender realisiert. Für ein akustisches Feedback für Fehler, Schuss und Treffer werden Buzzer verwendet.\
Die Räder werden mit zwei 360°-Servomotoren angetriebn. Diese besitzen drei Pins: GND, +5V, Steuersingal. Die beiden Pins GND und +5V werden direkt an den Spannungsregler angeschlossen, da ein Servomotor ca. 550mA Strom zieht. Der Pin für das Steuersignal wird an den ESP32-S2 angeschlossen.\
Über eine Webseite, die auf dem ESP-S2 läuft, kann man den Videostream des ESP-CAM sehen.
![Network.drawio.png](https://github.com/Siraman25/Infrabot/blob/master/Web-Interface/Network.drawio.png?raw=true)




