# Spannungsregler


Verwendeter Spannungsregler: LT1529-5

## **Charakterisitics**
* V<sub>Out</sub>= 5V
* I<sub>Max</sub>= 3A
* V<sub>DrouOut<sub>Min</sub></sub> at I<sub>Max</sub>= >0,6V 
* V<sub>In</sub><sub>Min</sub> at I<sub>Max</sub>= >5.6V 
* Thermisches Limit= 125°

## **Verwendung und Package**
Package: CT

 ![Spannungsregler_Package](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_Package.png?raw=true)
 
 Verwendung:
 
 ![Spannungsregler_Anwendung](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_Anwendung.png?raw=true)
 
 ## **Pins**
 * **OUTPUT**: 
 Dieser Pin Liefert die Spannung (V<sub>Out</sub>) und den Strom für die Last. Der 22$\mu$F Elektrolykondensator wird verwendet um Schwingungen zu vermeiden.
 * **SENSE**:
 Für die allermeisten Anwenudngen wird der SENSE-Pin direkt mit dem OUTPUT-Pin verbunden. Bei kritischen Anwendungen kleiner Spannungsabfälle wir dieser Pin zwischen Regler und Last geklemmt.
 * **GND**:
 Über den GND-Pin fällt die Spannung V<sub>DO</sub> ab. V<sub>DO</sub> ist die Differenz zwischen V<sub>In</sub> und V<sub>Out.
 * **<span style="text-decoration:overline">SHDN</span>**: 
 Der <span style="text-decoration:overline">SHDN</span> Pin ist für das Ein- bzw. Ausschalten des Gerätes zuständig. Bekommt diser Pin ein High-Signal so ist der Spannungsregler aktiv. Bei einem Low-Signal ist er inaktiv.
 * **V<sub>IN</sub>**:
 V<sub>IN</sub> ist der Input-Pin. Über ihn fließt die zu regulierende Eingangspannung (V<sub>In</sub>).
	
## **Thermische Probleme** 

![Spannungsregler_DropoutVoltage](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_DropoutVoltage.png?raw=true)
	
Bei einem maximalen Ausgangsstrom von 3A und einer Abfallsspannung von 0,7V erreicht der Spannungsregler eine Temperatur von 100°. Da wir unseren aber mit einer höheren Abfallsspannung zurechtkommen muss, werden wir ohne Kühlung das thermische Limit von 125° überschreiten. Um eine thermische Zerstörung zu vermeiden verwende wir folgenden Kühler für den Spannungsregler: [507302B00000G](https://www.digikey.it/en/products/detail/507302B00000G/HS115-ND/5849?itemSeq=383854613). 

![Spannungsregler_Kühler](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_Kühler.png?raw=true)

Dies ist ein Low-Profile Aluminium Kühlkörper, der 2,5W Leistung and die Umgebung abgibt.