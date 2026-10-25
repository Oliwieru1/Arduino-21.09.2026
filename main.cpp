const int liczbaCzujnikow = 4;

// KOLEJNOŚĆ W PROGRAMIE: 0 = GÓRNY, 1 = PRAWY (ZABLOKOWANY), 2 = DOLNY, 3 = LEWY

// Mapowanie działających pinów diod
const int pinyCzerwone[liczbaCzujnikow] = {9, 7, 5, 3};
const int pinyZielone[liczbaCzujnikow] = {8, 6, 2, 4}; 

const unsigned long czasPodtrzymania = 5000;

// Kolejka FIFO
int kolejka[liczbaCzujnikow];
int poczatekKolejki = 0;
int koniecKolejki = 0;
int liczbaWOgonku = 0;

bool wKolejce[liczbaCzujnikow] = {false, false, false, false};
bool poprzedniRuch[liczbaCzujnikow] = {false, false, false, false};

int aktywnyCzujnik = -1;
bool trwaPodtrzymanie = false;
unsigned long czasZakonczeniaRuchu = 0;

void dodajDoKolejki(int czujnik) {
  // Ignoruj uszkodzony/zwarty prawy czujnik (indeks 1), aby nie blokował całego skrzyżowania
  if (czujnik == 1 || wKolejce[czujnik] || aktywnyCzujnik == czujnik) {
    return;
  }
  if (liczbaWOgonku < liczbaCzujnikow) {
    kolejka[koniecKolejki] = czujnik;
    koniecKolejki = (koniecKolejki + 1) % liczbaCzujnikow;
    liczbaWOgonku++;
    wKolejce[czujnik] = true;
  }
}

int pobierzZKolejki() {
  if (liczbaWOgonku == 0) {
    return -1;
  }
  int czujnik = kolejka[poczatekKolejki];
  poczatekKolejki = (poczatekKolejki + 1) % liczbaCzujnikow;
  liczbaWOgonku--;
  wKolejce[czujnik] = false;
  return czujnik;
}

void ustawSwiatla() {
  for (int i = 0; i < liczbaCzujnikow; i++) {
    // Prawy kierunek (indeks 1) pomijamy, bo prąd i tak płynie tam poza kontrolą Arduino
    if (i == 1) {
      digitalWrite(pinyCzerwone[i], HIGH);
      digitalWrite(pinyZielone[i], LOW);
      continue;
    }

    // Normalna praca dla pozostałych stron skrzyżowania (GÓRA, DÓŁ, LEWO)
    if (i == aktywnyCzujnik) {
      digitalWrite(pinyCzerwone[i], LOW);
      digitalWrite(pinyZielone[i], HIGH);
    } else {
      digitalWrite(pinyCzerwone[i], HIGH);
      digitalWrite(pinyZielone[i], LOW);
    }
  }
}

void setup() {
  pinMode(13, INPUT_PULLUP); 
  pinMode(11, INPUT_PULLUP); 
  pinMode(12, INPUT_PULLUP); 
  pinMode(10, INPUT_PULLUP); 

  for (int i = 0; i < liczbaCzujnikow; i++) {
    pinMode(pinyCzerwone[i], OUTPUT);
    pinMode(pinyZielone[i], OUTPUT);
  }
  ustawSwiatla();
}

void loop() {
  unsigned long teraz = millis();
  bool ruch[liczbaCzujnikow];

  // Odczyt sprawnych kierunków:
  ruch[0] = (digitalRead(12) == HIGH); // Górny czujnik
  ruch[1] = false;                     // Prawy czujnik odcięty programowo
  ruch[2] = (digitalRead(10) == HIGH); // Dolny czujnik
  ruch[3] = (digitalRead(13) == HIGH && digitalRead(12) == LOW); // Lewy czujnik

  // Obsługa kolejki FIFO dla sprawnych kierunków
  for (int i = 0; i < liczbaCzujnikow; i++) {
    if (ruch[i] && !poprzedniRuch[i]) {
      dodajDoKolejki(i);
    }
    poprzedniRuch[i] = ruch[i];
  }

  if (aktywnyCzujnik >= 0) {
    if (ruch[aktywnyCzujnik]) {
      trwaPodtrzymanie = false;
    } else {
      if (!trwaPodtrzymanie) {
        trwaPodtrzymanie = true;
        czasZakonczeniaRuchu = teraz;
      }
      if (teraz - czasZakonczeniaRuchu >= czasPodtrzymania) {
        aktywnyCzujnik = -1;
        trwaPodtrzymanie = false;
      }
    }
  }

  if (aktywnyCzujnik == -1 && liczbaWOgonku > 0) {
    aktywnyCzujnik = pobierzZKolejki();
    trwaPodtrzymanie = false;
  }

  ustawSwiatla();
}
