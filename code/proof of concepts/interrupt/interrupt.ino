const int StartKnop = 2;
const int LedBlauw = 12;

// 'volatile' is verplicht voor variabelen die in een ISR worden aangepast
volatile bool StatusLed = false;
volatile unsigned long VorigeTijd = 0;
const unsigned long DebounceTijd = 200; // 200 ms filter tegen contactdender

void setup() {
  pinMode(LedBlauw, OUTPUT);
  pinMode(StartKnop, INPUT_PULLUP); // Interne pull-up weerstand inschakelen

  // LED start gegarandeerd uit
  digitalWrite(LedBlauw, LOW);

  // Interrupt triggert zodra de knop naar GND wordt getrokken (ingedrukt)
  attachInterrupt(digitalPinToInterrupt(StartKnop), KnopInterrupt, FALLING);
}

void loop() {
  // Werk de LED bij naar de huidige status
  digitalWrite(LedBlauw, StatusLed);
}

void KnopInterrupt() {
  unsigned long HuidigeTijd = millis();

  // Voorkom dat de interrupt meerdere keren per druk afgaat door dender
  if (HuidigeTijd - VorigeTijd > DebounceTijd) {
    StatusLed = !StatusLed; // Wissel status: LOW -> HIGH of HIGH -> LOW
    VorigeTijd = HuidigeTijd;
  }
}
