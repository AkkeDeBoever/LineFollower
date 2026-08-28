// Startknop (aangesloten tussen D2 en GND)
const int Knop = 2;

// Led (aangesloten op D12 met voorschakelweerstand)
const int LedBlauw = 12;

// DRV8833 Standby pin
const int STBY = 4;

// Motor A (Rechts)
const int AIN1 = 5;
const int AIN2 = 6;

// Motor B (Links)
const int BIN1 = 9;
const int BIN2 = 10;

// Snelheidsinstelling (0 - 255)
const int maxSnelheid = 50; 

// Variabelen
bool StatusKnop;

void setup() {
  Serial.begin(9600);

  pinMode(LedBlauw, OUTPUT);
  pinMode(Knop, INPUT_PULLUP); // Interne pull-up: ingedrukt = LOW
  
  pinMode(STBY, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);

  // Activeer de DRV8833 driver
  digitalWrite(STBY, HIGH);
}

void loop() {
  // Lees de knop uit (LOW bij indrukken)
  StatusKnop = digitalRead(Knop);

  if (StatusKnop == LOW)
  {
    // Knipperen blauwe LED (3x ter indicatie van start)
    for (int j = 0; j < 3; j++) {
      digitalWrite(LedBlauw, HIGH);
      delay(300);
      digitalWrite(LedBlauw, LOW);
      delay(300);
    }

    // 1. VOORWAARTS
    for (int i = 0; i <= maxSnelheid; i++)
    {
      analogWrite(AIN1, 0);
      analogWrite(AIN2, i);
      analogWrite(BIN1, 0);
      analogWrite(BIN2, i);
      delay(10);
    }
    for (int i = maxSnelheid; i >= 0; i--)
    {
      analogWrite(AIN1, 0);
      analogWrite(AIN2, i);
      analogWrite(BIN1, 0);
      analogWrite(BIN2, i);
      delay(10);
    }

    delay(2000);

    // 2. ACHTERWAARTS
    for (int i = 0; i <= maxSnelheid; i++)
    {
      analogWrite(AIN1, i);
      analogWrite(AIN2, 0);
      analogWrite(BIN1, i);
      analogWrite(BIN2, 0);
      delay(10);
    }
    for (int i = maxSnelheid; i >= 0; i--)
    {
      analogWrite(AIN1, i);
      analogWrite(AIN2, 0);
      analogWrite(BIN1, i);
      analogWrite(BIN2, 0);
      delay(10);
    }

    delay(2000);

    // 3. LINKS DRAAIEN
    for (int i = 0; i <= maxSnelheid; i++)
    {
      analogWrite(AIN1, 0);
      analogWrite(AIN2, i);
      analogWrite(BIN1, i);
      analogWrite(BIN2, 0);
      delay(10);
    }
    for (int i = maxSnelheid; i >= 0; i--)
    {
      analogWrite(AIN1, 0);
      analogWrite(AIN2, i);
      analogWrite(BIN1, i);
      analogWrite(BIN2, 0);
      delay(10);
    }

    delay(2000);

    // 4. RECHTS DRAAIEN
    for (int i = 0; i <= maxSnelheid; i++)
    {
      analogWrite(AIN1, i);
      analogWrite(AIN2, 0);
      analogWrite(BIN1, 0);
      analogWrite(BIN2, i);
      delay(10);
    }
    for (int i = maxSnelheid; i >= 0; i--)
    {
      analogWrite(AIN1, i);
      analogWrite(AIN2, 0);
      analogWrite(BIN1, 0);
      analogWrite(BIN2, i);
      delay(10);
    }
  }
}
