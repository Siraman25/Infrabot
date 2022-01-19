# PS3Controller\
## Biblioteken\
### https://github.com/jvpernis/esp32-ps3\
<code>Ps3.begin("MAC_Adresse");</code> ist dazu da die mac adresse des Ps3controllers dem esp32 zu geben, damit dieser sich mit dem Controller verbinden kann.\
<code>Ps3.attachOnConnect(onConnect);</code> ist dazu da in einem void (onConnect) zu springen aus dem erst wieder herrausgesprungen wird sobalt der Controller verbunden ist.\
<code>Ps3.attach(notify);</code> ist dazu da in den void (notify) zu springen wo die Knöfe und Joysticks des Controllers ausgelesen werden.\
<code>Ps3.event.analog_change.button.l1</code> ist dazu da den shoulderbutton in einem analogwert auszulesen. das l1 am ende kann mit r1, r2, l2 ausgewechselt werden je nachdem welcher button ausgelesen werden soll.\
<code>Ps3.data.analog.stick.rx</code>: dieser Befehl ließt die Werte des Joysticks aus. rx kann mit ry,ly, lx ausgewechselt werden je nachdem welcher Joystick und welche achsen des Joysticks benötigt werden. Die X-Achse gibt werte von -128(links) bis 127(rechts) aus.Die Y-Achse gibt auchh die Werte -128(vorne) bis 127(hinten) aus.\
<code>Ps3.data.button.cross>/code>: dieser Befehl liest din X button auf der rechten Seite des Controllers aus. Wenn mann "cross" mit "triangle", "square" oder "circle" austauscht werden die andern 3 buttons ausgelesen.\
