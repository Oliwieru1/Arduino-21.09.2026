
#include <Servo.h>
#include <IRremote.hpp>

Servo serwo1, serwo2;

#define IR_PIN 10
#define POWER 0x00
#define LED 12
#define PIR_PIN 4

// DEFINICJE STANOW
#define STAN_ZAMKNIETA 0
#define STAN_OTWARTA 1
#define STAN_OTWIERANIE 4
#define STAN_ZAMYKANIE 5
#define STAN_ZATRZYMANIE 6

int pozycja1 = 0;
int pozycja2 = 180;

int cel1 = 0;
int cel2 = 180;

int stan = STAN_ZAMKNIETA;
int kierunek = STAN_OTWIERANIE;

bool ruch = false;

unsigned long czas = 0;
unsigned long przycisk = 0;

// ZAMKNIETA
void zamknieta() {
  cel1 = 0;
  cel2 = 180;
  stan = STAN_ZAMKNIETA;
  ruch = false;
}

// OTWARTA
void otwarta() {
  cel1 = 90;
  cel2 = 90;
  stan = STAN_OTWARTA;
  ruch = false;
}

// OTWIERANIE
void otwieranie() {
  cel1 = 90;
  cel2 = 90;
  stan = STAN_OTWIERANIE;
  kierunek = STAN_OTWIERANIE;
  ruch = true;
}

// ZAMYKANIE
void zamykanie() {
  cel1 = 0;
  cel2 = 180;
  stan = STAN_ZAMYKANIE;
  kierunek = STAN_ZAMYKANIE;
  ruch = true;
}

// ZATRZYMANIE
void zatrzymanie() {

  if (stan == STAN_ZAMYKANIE) {
    kierunek = STAN_OTWIERANIE;
  }
  else {
    kierunek = STAN_ZAMYKANIE;
  }

  cel1 = pozycja1;
  cel2 = pozycja2;

  ruch = false;
  stan = STAN_ZATRZYMANIE;
}

// OBSLUGA POWER
void obslugaPower() {

  switch (stan) {

    case STAN_ZAMKNIETA:
      otwieranie();
      break;

    case STAN_OTWARTA:
      zamykanie();
      break;

    case STAN_OTWIERANIE:
    case STAN_ZAMYKANIE:
      zatrzymanie();
      break;

    case STAN_ZATRZYMANIE:

      switch (kierunek) {

        case STAN_OTWIERANIE:
          otwieranie();
          break;

        case STAN_ZAMYKANIE:
          zamykanie();
          break;
      }
      break;
  }
}

// OBSLUGA PIR
void obslugaPIR() {

  int czujnik = digitalRead(PIR_PIN);

  switch (stan) {

    case STAN_ZAMYKANIE:

      if (czujnik == HIGH) {
        Serial.println("RUCH WYKRYTY!");
        Serial.println("ZAMIANA KIERUNKU NA OTWIERANIE!");

        otwieranie();
      }

      break;

    default:
      break;
  }
}

// STEROWANIE SERWAMI
void sterowanieSerwami() {

  if (!ruch || millis() - czas < 15) return;

  czas = millis();

  if (pozycja1 < cel1) pozycja1++;
  else if (pozycja1 > cel1) pozycja1--;

  if (pozycja2 < cel2) pozycja2++;
  else if (pozycja2 > cel2) pozycja2--;

  serwo1.write(pozycja1);
  serwo2.write(pozycja2);

  if (pozycja1 == cel1 && pozycja2 == cel2) {

    switch (stan) {

      case STAN_OTWIERANIE:
        otwarta();
        Serial.println("BRAMA OTWARTA");
        break;

      case STAN_ZAMYKANIE:
        zamknieta();
        Serial.println("BRAMA ZAMKNIETA");
        break;
    }
  }
}

// ODCZYT PILOTA
void obslugaPilota() {

  if (!IrReceiver.decode()) return;

  if (IrReceiver.decodedIRData.command == POWER &&
      !(IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) &&
      millis() - przycisk > 300) {

    przycisk = millis();
    obslugaPower();
  }

  IrReceiver.resume();
}

// SETUP
void setup() {

  Serial.begin(9600);

  serwo1.attach(3);
  serwo2.attach(5);

  pinMode(LED, OUTPUT);
  pinMode(PIR_PIN, INPUT);

  serwo1.write(pozycja1);
  serwo2.write(pozycja2);

  IrReceiver.begin(IR_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("SYSTEM GOTOWY");
}

// LOOP
void loop() {

  obslugaPIR();

  obslugaPilota();

  sterowanieSerwami();

  digitalWrite(LED, ruch);
}
