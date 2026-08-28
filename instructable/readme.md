# Instructable

Een instructable is een stappenplan - zonder verdere uitleg - hoe je vertrekkend van de bill of materials en gebruik makend van de technische tekeningen de robot kan nabouwen. Ook de nodige stappen om de microcontroller te compileren en te uploaden staan beschreven.  

## Stap 1: Onderdelen verzamelen (BOM-check)

Microcontroller: Arduino Leonardo (ATmega32U4)

Motor driver: DRV8833 Dual H-Brug module

Aandrijving: 2× N20 Micro Metal Gear DC-motoren (30:1, 100 RPM)

Sensoren: Pololu QTR-8A reflectie sensor array (analoog)

Draadloze communicatie: HC-06 Bluetooth module

Voeding: 2× 18650 Li-ion batterijen (7,4 V) in 2S batterijhouder + lader

Chassis & Loopwerk: 3D-geprint chassis, 2 rubberen wielen, 1 kogelwiel (caster)

Elektronica & Montage: Breadboard, jumper wires (Dupont kabels), drukschakelaar

Ontkoppeling/Ruisfiltering: 2× 100 nF keramische condensatoren, 1× 100 µF elektrolytische condensator

## Stap 2: Chassis maken en voorbereiden

Snijdt het hout zodat het afgestemd is op N20 micro gear motoren en de QTR-8A sensor.
Trek een duidelijke lijn op het hout zodat de N20 motoren in 1 lijn staan met elkaar

## Stap 3: Mechanische assemblage

Plaats de twee N20 motoren in de motorbeugels van het chassis en zet ze vast.

Druk de rubberen wielen stevig op de D-vormige assen van de N20 motoren.

Monteer het kogelwiel aan de voorzijde van de onderkant van het chassis.

Bevestig de 18650 batterijhouder op het chassis (bij voorkeur centraal voor een gunstig zwaartepunt).

Monteer de QTR-8A sensor aan de voorzijde, zo dicht mogelijk bij de grond (optimale meetafstand: 3 mm boven het rijoppervlak).

Plaats het breadboard en de Arduino Leonardo stevig op de bovenplaat.

## Stap 4: Elektrische verbindingen maken

### Voeding en afvlakking:

Verbind de geschakelde batterijspanning (7,4 V) met de VIN van de Arduino Leonardo en de VCC/VM van de DRV8833.

Sluit alle aardes (GND) aan op een gemeenschappelijke massarail op het breadboard.

Plaats de 100 µF elektrolytische condensator parallel over de voedingsrail (let op de polariteit: minstreep naar GND).

### DRV8833 H-brug & Motoren:

Verbind STBY van de DRV8833 met de D4 van de microcontroller (hoog) om de driver in te schakelen.

Sluit de ingangspinnen van de driver (IN1, IN2, IN3, IN4) aan op PWM-capabele pinnen van de Arduino Leonardo (bv. pinnen 5, 6, 9, 10).

Verbind motoruitgangen OUT1/OUT2 met de linkermotor en OUT3/OUT4 met de rechtermotor.

Plaats telkens een 100 nS keramische condensator parallel over de twee aansluitlipjes van elke N20 motor om inductieve borstelruis te onderdrukken.

### QTR-8A Sensor:

Sluit VCC aan op 5V en GND op aarde.

Verbind de analoge sensoruitgangen (2 t/m 7) met de analoge ingangen van de Leonardo (A0 t/m A5).
Verbind sensorkanaal D7 aan de linkerzijde van de wagen met analoge pin A0, zodat dit overeenkomt met de meest linkse index in de array.

### HC-06 Bluetooth module
Voed de module met 5V en GND.Verbind de TXD van de HC-06 met pin 0 (RX) van de Arduino Leonardo.

Verbind de RXD van de HC-06 met pin 1 (TX) van de Arduino Leonardo (optioneel via een spanningsdeler 5V $\rightarrow$ 3,3V).

Op de Leonardo communiceert dit direct via Serial1 in plaats van de USB Serial

## Stap 5: Firmware configureren en uploaden

Open de Arduino IDE en laad de robotfirmware in.

Selecteer in het menu Hulpmiddelen (Tools):

Board: Arduino Leonardo

Poort: Selecteer de actieve virtuele COM-poort van de Leonardo.

Zorg dat de code gebruikmaakt van de QTRSensors bibliotheek en Serial1 voor de HC-06 communicatie.

Compileer en upload het programma via de micro-USB kabel naar de Leonardo.

## Stap 6: Kalibratie uitvoeren

Koppel de Arduino los van de pc en schakel de batterijvoeding in.

Koppel je smartphone via Bluetooth aan de HC-06 (pincode is meestal 1234 of 0000).

Open een Bluetooth Terminal app:

Plaats de sensoren boven de zwarte lijn en activeer de kalibratieroutine. ('calibrate black' en 'calibrate white'

## Stap 7: Testen en PID finetunen

Plaats de wagen op het testparcours.

Start de lijnvolgmodus.

Pas via de Bluetooth Terminal de regellusparameters (PID-waarden: Kp, Ki, Kd) en de basissnelheid aan totdat de robot schokvrij en accuraat de lijn volgt bij bochten.

## Stap 8: De robot is nu klaar voor gebruik!
