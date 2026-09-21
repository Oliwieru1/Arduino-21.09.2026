int diody[] = {9, 10, 11, 12};

unsigned long zapCzas = 0;

void setup()
{
  for (int i = 0; i < 4; i++) {
    pinMode(diody[i], OUTPUT);
  }
}

void loop()
{
  unsigned long czas = millis();
  unsigned long etap = czas - zapCzas;

  // 0-4 sekundy
  // 9 = czerwone, 10 = zielone
  if (etap < 4000) {
    digitalWrite(9, HIGH);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
  }

  // 4-6 sekund
  // Dwie czerwone
  else if (etap < 6000) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }

  // 6-10 sekund
  // 11 = czerwone, 12 = zielone
  else if (etap < 10000) {
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, HIGH);
  }

  // 10-12 sekund
  // Dwie czerwone
  else if (etap < 12000) {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
  }

  // Od początku
  else {
    zapCzas = czas;
  }
}
