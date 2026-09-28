// Definicja pinów dla 4 kierunków
const int CZERWONA_GORNA = 2;
const int ZIELONA_GORNA  = 3;

const int CZERWONA_PRAWA = 4;
const int ZIELONA_PRAWA  = 5;

const int CZERWONA_DOLNA = 6;
const int ZIELONA_DOLNA  = 7;

const int CZERWONA_LEWA  = 8;
const int ZIELONA_LEWA   = 9;

// Tablice z pinami (0: Góra, 1: Prawo, 2: Dół, 3: Lewo)
const int pinyCzerwone[] = {CZERWONA_GORNA, CZERWONA_PRAWA, CZERWONA_DOLNA, CZERWONA_LEWA};
const int pinyZielone[]  = {ZIELONA_GORNA, ZIELONA_PRAWA, ZIELONA_DOLNA, ZIELONA_LEWA};

// Zmienne do obsługi czasowej millis()
unsigned long poprzedniCzas = 0;
int aktualnyKierunek = 0; // 0=Góra, 1=Prawo, 2=Dół, 3=Lewo
bool fazaCzerwona = true;  // true = faza wszystkich czerwonych (2s), false = faza jednej zielonej + reszta czerwonych (4s)

void ustawSwiatla(int zielonyKierunek) {
  // Wyłączamy wszystkie zielone
  for (int i = 0; i < 4; i++) {
    digitalWrite(pinyZielone[i], LOW);
  }

  if (zielonyKierunek == -1) {
    // Wszędzie czerwone (faza 2 sekundy)
    for (int i = 0; i < 4; i++) {
      digitalWrite(pinyCzerwone[i], HIGH);
    }
  } else {
    // Jeden kierunek ma ZIELONE, a pozostałe 3 mają CZERWONE (faza 4 sekundy)
    for (int i = 0; i < 4; i++) {
      if (i == zielonyKierunek) {
        digitalWrite(pinyCzerwone[i], LOW);  // Gasimy czerwoną na aktywnym kierunku
        digitalWrite(pinyZielone[i], HIGH);  // Zapalamy zieloną na aktywnym kierunku
      } else {
        digitalWrite(pinyCzerwone[i], HIGH); // DLA INNYCH KIERUNKÓW CZERWONA ZOSTANIE WŁĄCZONA
      }
    }
  }
}

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(pinyCzerwone[i], OUTPUT);
    pinMode(pinyZielone[i], OUTPUT);
  }
  
  // Stan początkowy: wszystkie czerwone
  ustawSwiatla(-1);
}

void loop() {
  unsigned long aktualnyCzas = millis();

  // FAZA 1: Wszystkie 4 czerwone świecą przez 2000 ms (2 s)
  if (fazaCzerwona) {
    if (aktualnyCzas - poprzedniCzas >= 2000) {
      poprzedniCzas = aktualnyCzas;
      fazaCzerwona = false; // Przejście do fazy zielonego światła

      // Włączamy zieloną dla wybranego kierunku, reszta ma czerwone
      ustawSwiatla(aktualnyKierunek);
    }
  } 
  // FAZA 2: Jedna zielona + pozostałe trzy czerwone przez 4000 ms (4 s)
  else {
    if (aktualnyCzas - poprzedniCzas >= 4000) {
      poprzedniCzas = aktualnyCzas;
      fazaCzerwona = true; // Przejście do fazy wszystkich czerwonych

      // Zmiana kierunku na następny w ruchu wskazówek zegara
      aktualnyKierunek = (aktualnyKierunek + 1) % 4;

      // Powrót do stanu: wszystkie czerwone
      ustawSwiatla(-1);
    }
  }
}
