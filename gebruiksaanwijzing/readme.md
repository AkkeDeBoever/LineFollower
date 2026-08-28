# Gebruiksaanwijzing

## opladen / vervangen batterijen
De auto werkt op LiPo 2S-batterijen. Laad deze uitsluitend op met een geschikte LiPo-oplader en volg de standaard veiligheidsvoorschriften voor lithium-polymeeraccu's bij het laden en vervangen.

## draadloze communicatie
### Smartphone (Android via Bluetooth)
De robot gebruikt een Bluetooth-module die compatibel is met Android.

Bluetooth inschakelen: Ga naar de Bluetooth-instellingen op je Android-toestel en zoek naar nieuwe apparaten.

Koppelen: Selecteer de Bluetooth-module van de robot en voer indien nodig de koppelcode in (vaak 1234 of 0000).

App openen: Start de app Serial Bluetooth Terminal.

### Laptop: Verbinden via PuTTY
Bij een laptop kun je communiceren via een fysieke kabel (Seriële COM-poort) of draadloos via Wi-Fi.
#### Seriële verbinding via COM-poort (USB-kabel)
Gebruik de juiste USB-naar-serieel kabel.

Sluit de robot aan: Verbind de robot via een USB-kabel met je laptop.

COM-poort achterhalen (Windows):Druk op Windows-toets + X en kies Apparaatbeheer (Device Manager).

Klap het onderdeel Poorten (COM & LPT) open.

Kijk naar de poortnaam van de aangesloten chip (bijv. USB-SERIAL), gevolgd door het poortnummer, bijvoorbeeld COM3 of COM4.
PuTTY configureren:

Open PuTTY.

Selecteer onder Connection type de optie Serial.

Typ bij Serial line jouw poortnummer in (bijv. COM3).

Stel bij Speed (Baudrate) de juiste snelheid in (meestal 9600, afhankelijk van je microcontrollercode).

Sessie openen: Klik op Open. De terminal opent en je kunt commando's typen.
## commando's
run – Start de motor en start het rijprogramma.

stop – Brengt het voertuig direct tot stilstand.

debug [on/off] – Toont of verbergt actuele parameterwaarden en sensordata.

calibrate black – Slaat de referentiewaarde voor zwart op.

calibrate white – Slaat de referentiewaarde voor wit op.

set cycle [µs] – Wijzigt de cyclusduur in microseconden.

set power [0..255] – Stelt het aandrijfvermogen in.

set diff [0..1] – Bepaalt de bochtsnelheid (hogere waarde = minder vertraging in bochten).

set kp [waarde] – Regelt de reactiesnelheid van de besturing (te hoog leidt tot trillingen).

set ki [waarde] – Verhoogt stuurcorrectie bij langdurige afwijkingen.

set kd [waarde] – Dempt abrupte stuurbewegingen veroorzaakt door een hoge Kp.
## kalibratie
Kalibreer de optische sensoren altijd vóór vertrek op de daadwerkelijke ondergrond:

Zwart kalibreren: Plaats de sensoren op het zwarte baanoppervlak en stuur het commando calibrate black.

Wit kalibreren: Plaats de sensoren op het witte baanoppervlak en stuur het commando calibrate white.

Let op: Gebruik uitsluitend puur zwarte en witte referentievlakken. Afwijkende tinten of tussenkleuren verstoren de lijnherkenning.  

## settings
Power: 160
diff: 0.60
kp: 16.00
Ki: 0.00
Kd: 0.20

### start/stop button
De start/stop knop bevindt zich op het breadboard.
