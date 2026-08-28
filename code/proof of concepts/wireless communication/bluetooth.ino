void setup() {
  Serial.begin(9600);   // USB Seriële Monitor naar je PC
  Serial1.begin(9600);  // Bluetooth verbinding (Pin 0 RX, Pin 1 TX)
  
  Serial.println("Klaar! Typ in PuTTY om tekst hier te zien.");
}

void loop() {
  // Lees uit PuTTY (Bluetooth) en print direct naar de Serial Monitor (USB)
  if (Serial1.available()) {
    char c = Serial1.read();
    Serial.write(c);   // Naar Arduino Serial Monitor
    Serial1.write(c);  // Echo terug naar PuTTY
  }

  // Optioneel: Typ in Serial Monitor en stuur naar PuTTY
  if (Serial.available()) {
    char c = Serial.read();
    Serial1.write(c);
  }
}
