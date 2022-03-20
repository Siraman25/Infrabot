# Spannungsregler


Verwendeter Spannungsregler: LT1529

## Charakterisitics
* V<sub>Out</sub>= 3,3V - 14V
* I<sub>Max</sub>= 3A
* V<sub>DropOut<sub>Min</sub></sub> at I<sub>Max</sub>= >0,6V
* Thermisches Limit= 125°

## Verwendung und Package
Package: CT

 ![Spannungsregler_Package](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_Package.png?raw=true)
 
 Verwendung:
 
 ![Spannungsregler_Anwendung](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_Anwendung.png?raw=true)
 
 ## Pins
 * **OUTPUT**: 
 Dieser Pin Liefert die Spannung (V<sub>Out</sub>) und den Strom für die Last. Der 22$\mu$F Elektrolykondensator wird verwendet um Schwingungen zu vermeiden.
 * **SENSE**:
 Dieser Pin ist auch als ADJ-Pin bekannt. Zur Wahl der Ausgangsspannung wird hier ein Spannungsteiler eingebaut.
 * **GND**:
 Über den GND-Pin fällt die Spannung V<sub>DO</sub> ab. V<sub>DO</sub> ist die Differenz zwischen V<sub>In</sub> und V<sub>Out.
 * **<span style="text-decoration:overline">SHDN</span>**: 
 Der <span style="text-decoration:overline">SHDN</span> Pin ist für das Ein- bzw. Ausschalten des Gerätes zuständig. Bekommt diser Pin ein High-Signal so ist der Spannungsregler aktiv. Bei einem Low-Signal ist er inaktiv.
 * **V<sub>IN</sub>**:
 V<sub>IN</sub> ist der Input-Pin. Über ihn fließt die zu regulierende Eingangspannung (V<sub>In</sub>).

## Berechnung des Spannungsteilers
**Gegeben:**
U<sub>OUT</sub>= 5V\
U<sub>R1</sub>= 3,75V\
U<sub>R2</sub>= 1,25V\
I<sub>SENSE</sub>= 150nA
	
**Wahl:**
R<sub>1</sub>= 100kΩ
	
**Rechnung:**
	I<sub>R1</sub> = U<sub>R1</sub> : R<sub>1</sub> -> 3,75V : 100kΩ = 37,5µA\
	I<sub>R2</sub> = I<sub>R1</sub> - I<sub>SENSE</sub> -> 37,5µA - 150nA = 37,35µA\
	R<sub>2</sub> = U<sub>R2</sub> : I<sub>R2</sub> -> 1,25V : 37,35µA = 33467,202Ω ≈ 33kΩ
	
**Probe:**
	U<sub>OUT</sub> = U<sub>R1</sub> x (1 + (R<sub>2</sub> : R<sub>1</sub>)) + (I<sub>SENSE</sub> x R<sub>2</sub>) -> 3,75V x (1 + (33kΩ : 100kΩ)) +(150nA x 33kΩ) = 4,99245V
	
## Thermische Probleme

![Spannungsregler_DropoutVoltage](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_DropoutVoltage.png?raw=true)
	
Bei einem maximalen Ausgangsstrom von 3A und einer Abfallsspannung von 0,7V erreicht der Spannungsregler eine Temperatur von 100°. Da wir unseren aber mit einer höheren Abfallsspannung zurechtkommen muss, werden wir ohne Kühlung das thermische Limit von 125° überschreiten. Um eine thermische Zerstörung zu vermeiden verwende wir einen Kühler für das Package TO-220. 

![Spannungsregler_Kühler](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_K%C3%BChler.jpg?raw=true)

Dies ist ein Low-Profile Aluminium Kühlkörper, der P<sub>Kühler</sub> = 3W Leistung and die Umgebung abgibt.
	
## **Leistungsberechnung**
	
Thermischer Widerstand:
![Spannungsregler_ThermischerWiderstand](https://github.com/Siraman25/Infrabot/blob/master/Dokumentation/Bilder/Spannungsregler/Spannungsregler_ThermischerWiderstand.png?raw=true)
	
**Gegeben:**
	V<sub>In</sub> = 6,7V\
	V<sub>OUT</sub> = 5V
	I<sub>GES</sub> = 2,5A\
	P<sub>Kühler</sub> = 3W\
	T<sub>Umgebung</sub>≈ 30°C\
	
**Rechnung:**
	U<sub>DropOut</sub> = V<sub>In</sub> - V<sub>Out</sub> -> 6,7V - 5V = 1,7V\
	P<sub>GES</sub> = U<sub>DropOut</sub> x I<sub>GES</sub> -> 1,7V x 2,5A = 4,25W\
	P<sub>VR</sub> = P<sub>GES</sub> - P<sub>Kühler</sub> -> 4,25W - 3W = 1,25W\
	T<sub>VR</sub> = P<sub>VR</sub> x 50°C/W -> 1,25W x 50°C/W = 62,5°C\
	T<sub>GES</sub> = T<sub>Umgebung</sub> + T<sub>VR</sub> -> 30°C + 62,5°C = 92,5°C
