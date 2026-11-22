
#include <Keypad.h>

#define BUZZER 10
#define PIR 9

#define LED_CZERWONA 11
#define LED_ZIELONA 12
#define LED_ZOLTA 13

// Trzy stany alarmu
#define STAN_UZBRAJANIA 1
#define STAN_UZBROJONY 2
#define STAN_ALARM 3

const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {1, 2, 3, 4};
byte colPins[COLS] = {5, 6, 7, 8};

Keypad keypad = Keypad(makeKeymap(keys),
                       rowPins, colPins,
                       ROWS, COLS);

int stanAlarmu = STAN_UZBRAJANIA;

bool systemON = false;

unsigned long czasUzbrajania = 0;

void setup() {

  pinMode(BUZZER, OUTPUT);
  pinMode(PIR, INPUT);

  pinMode(LED_CZERWONA, OUTPUT);
  pinMode(LED_ZIELONA, OUTPUT);
  pinMode(LED_ZOLTA, OUTPUT);

  digitalWrite(LED_CZERWONA, LOW);
  digitalWrite(LED_ZIELONA, LOW);
  digitalWrite(LED_ZOLTA, LOW);

  Serial.begin(9600);

  Serial.println("Nacisnij # aby wlaczyc system");
}

void loop() {

  // Wlaczanie systemu klawiszem #
  if (!systemON) {

    char key = keypad.getKey();

    if (key == '#') {

      systemON = true;
      stanAlarmu = STAN_UZBRAJANIA;

      czasUzbrajania = millis();

      Serial.println("UZBRAJANIE SYSTEMU...");
    }

    return;
  }

  // OBSLUGA TRZECH STANOW
  switch (stanAlarmu) {

    // STAN 1 - UZBRAJANIE
    case STAN_UZBRAJANIA:

      digitalWrite(LED_CZERWONA, LOW);
      digitalWrite(LED_ZIELONA, LOW);
      digitalWrite(LED_ZOLTA, HIGH);

      if (millis() - czasUzbrajania >= 5000) {

        digitalWrite(LED_ZOLTA, LOW);

        stanAlarmu = STAN_UZBROJONY;

        Serial.println("SYSTEM UZBROJONY!");
      }

      break;


    // STAN 2 - SYSTEM UZBROJONY
    case STAN_UZBROJONY:

      digitalWrite(LED_CZERWONA, LOW);
      digitalWrite(LED_ZIELONA, HIGH);
      digitalWrite(LED_ZOLTA, LOW);

      noTone(BUZZER);

      if (digitalRead(PIR) == HIGH) {

        stanAlarmu = STAN_ALARM;

        Serial.println("WYKRYTO RUCH!");
      }

      break;


    // STAN 3 - ALARM
    case STAN_ALARM:

      digitalWrite(LED_CZERWONA, HIGH);
      digitalWrite(LED_ZIELONA, LOW);
      digitalWrite(LED_ZOLTA, LOW);

      tone(BUZZER, 2000);

      if (digitalRead(PIR) == LOW) {

        noTone(BUZZER);

        stanAlarmu = STAN_UZBROJONY;

        Serial.println("BRAK RUCHU - SYSTEM CZUWA");
      }

      break;
  }
}
