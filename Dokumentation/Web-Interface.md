# Web-Interface
Die Web-Interface zeigt das Video-Feed des ESP32-CAM-Moduls, im Code vom ESP32-CAM werden die verschiedenen Video-Einstellungen eingestellt.
Die originelle Idee wäre die gewesen, dass man den Punktestand der zwei Roboter sieht. Diese Funktion wurde allerdings nicht implementiert, da es ohne Infrarot-System (bzw. ohne 2. Roboter) keinen Sinn ergibt, die Punkte zu zählen.
Als basis der HTML-Datei wurde die standard-Library des ESP32-CAM benutzt. Dann wurde der Container des Video-Feeds geändert, um die Möglichkeit, vom Browser Einstellungen zu ändern, zu entfernen.