# **Infrarot-Roboter**
## **Beschreibung**
Bei diesen Inrarot-Robotern handelt es sich um zwei auf Rädern fahrenden Robotern welche als "Shooter-Spiel" konzipiert sind. Sie werden über zwei ESP-32 gesteuert (ESP32-CAM & ESP32-S2). Bedient werden sie entweder mit einem PS3-Controller oder über eine Website via PC oder Smartphone. Die Steuerung über PS3-Controller wird durch eine Bluetooth-Verbindung zwischen Controller und ESP32-S2 realisiert.\
Sie können sich gegenseitig abschießen. Dies wird mit Infrarot-Empfänger und -Sender realisiert. Für ein akustisches Feedback für Fehler, Schuss und Treffer werden Buzzer verwendet.\
Die Räder werden mit zwei 360°-Servomotoren angetriebn. Diese besitzen drei Pins: GND, +5V, Steuersingal. Die beiden Pins GND und +5V werden direkt an den Spannungsregler angeschlossen, da ein Servomotor ca. 550mA Strom zieht. Der Pin für das Steuersignal wird an den ESP32-S2 angeschlossen.\
Über eine Webseite, die auf dem ESP-S2 läuft, kann man den Videostream des ESP-CAM sehen.

## **Beschreibung**
##### Servo
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Servo.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: Continous servo FS90R
<code>Preis</code>: € 21,81	(4 Stück)
<code>Link</code>: [Click-here](https://it.aliexpress.com/item/32984667875.html?gatewayAdapt=glo2ita&spm=a2g0o.productlist.0.0.757d6a76EX7cRW&algo_pvid=e50159a6-6599-4880-aa28-8534ffaa9490&algo_exp_id=e50159a6-6599-4880-aa28-8534ffaa9490-0&pdp_ext_f=%7B%22sku_id%22%3A%2266784030012%22%7D)
##### Batteriehalterung
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Batteriehalter.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: 
<code>Preis</code>: 
<code>Link</code>: [Click-here]()
##### Powermanagement

<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Baumanagement.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: 
<code>Preis</code>: 
<code>Link</code>: [Click-here]()
##### ESP32 Cam-Module
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\ESP32-Cam-Module.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: 113990580
<code>Preis</code>: € 8,99000 (1 Stück)
<code>Link</code>: [Click-here](https://www.digikey.it/it/products/detail/seeed-technology-co-ltd/113990580/9697033)
##### Hilfsrad
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Hilfsrad.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>:  Universalrad
<code>Preis</code>:  € 5,95
<code>Link</code>: [Click-here](https://it.aliexpress.com/item/4001072165757.html?gatewayAdapt=glo2ita&spm=a2g0o.detail.1000014.41.601489317OgLFP&gps-id=pcDetailBottomMoreOtherSeller&scm=1007.13338.183347.0&scm_id=1007.13338.183347.0&scm-url=1007.13338.183347.0&pvid=666dd3e0-f355-4ce7-bd33-32656806e43c&_t=gps-id:pcDetailBottomMoreOtherSeller,scm-url:1007.13338.183347.0,pvid:666dd3e0-f355-4ce7-bd33-32656806e43c,tpp_buckets:668%232846%238111%231996&&pdp_ext_f=%7B%22sceneId%22:%2223416%22,%22sku_id%22:%2210000014060064385%22%7D)
##### Infrarot LED
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Infrarot-LED.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: # TSAL6100
<code>Preis</code>: € 0,47000 (1 Stück)
<code>Link</code>: [Click-here](https://www.digikey.it/it/products/detail/vishay-semiconductor-opto-division/TSAL6100/1681338)
##### Infrarot Reciever
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\IR-Reciever.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: TSSP58038
<code>Preis</code>: € 1,42000 (1 Stück)
<code>Link</code>: [Click-here](https://www.digikey.it/it/products/detail/vishay-semiconductor-opto-division/TSSP58038/4695717)
##### Button
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Button.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: 
<code>Preis</code>: 
<code>Link</code>: [Click-here]()
##### Switch
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Switch.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>: 
<code>Preis</code>: 
<code>Link</code>: [Click-here]()
##### Kühler
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Kühler.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>:  PS3-Controller
<code>Preis</code>: 
<code>Link</code>: [Click-here]()
##### Spannungsregler
<img src="Z:\Schule\4BEL\Füla\Infrabot\Dokumentation\Bilder\Bauteile\Spannungsregler.jpg"  style="height: 400px; width:300px;"/>

<code>Name</code>:  LT1529-5
<code>Preis</code>: 
<code>Link</code>: [Click-here]()