// ZESTAW 1 (Górna para)
int zielone1 = 8;   // Pin 8 idzie do zielonej diody na górze
int czerwone1 = 9;  // Pin 9 idzie do czerwonej diody pod nią

// ZESTAW 2 (Dolna para)
int zielone2 = 10;  // Pin 10 idzie do zielonej diody na dole
int czerwone2 = 11; // Pin 11 idzie do czerwonej diody na dole

// CZUJNIKI RUCHU (Żółty i różowy przewód z pinów 2 i 3)
int czujnik1 = 2; 
int czujnik2 = 3; 

int stan1 = LOW;
int stan2 = LOW;

int poprzedni1 = LOW;
int poprzedni2 = LOW;

void setup() {
  pinMode(zielone1, OUTPUT);
  pinMode(czerwone1, OUTPUT);
  pinMode(zielone2, OUTPUT);
  pinMode(czerwone2, OUTPUT);

  pinMode(czujnik1, INPUT);
  pinMode(czujnik2, INPUT);

  wszystkieCzerwone();
}

void wszystkieCzerwone() {
  digitalWrite(czerwone1, HIGH);  // Włącz czerwoną 1
  digitalWrite(czerwone2, HIGH);  // Włącz czerwoną 2

  digitalWrite(zielone1, LOW);   // Zgaś zieloną 1
  digitalWrite(zielone2, LOW);   // Zgaś zieloną 2
}

void zieloneSwiatlo(int nr) {
  wszystkieCzerwone();

  if (nr == 1) {
    digitalWrite(czerwone1, LOW);
    digitalWrite(zielone1, HIGH);
  }
  else if (nr == 2) {
    digitalWrite(czerwone2, LOW);
    digitalWrite(zielone2, HIGH);
  }
}

void loop() {
  stan1 = digitalRead(czujnik1);
  stan2 = digitalRead(czujnik2);

  // Wykrycie ruchu na czujniku 1 -> zielone dla zestawu 1
  if (stan1 == HIGH && poprzedni1 == LOW) {
    zieloneSwiatlo(1);
  }
  // Wykrycie ruchu na czujniku 2 -> zielone dla zestawu 2
  else if (stan2 == HIGH && poprzedni2 == LOW) {
    zieloneSwiatlo(2);
  }

  poprzedni1 = stan1;
  poprzedni2 = stan2;

  delay(20);
}
