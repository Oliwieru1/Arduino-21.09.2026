# System alarmowy Arduino Uno R3

## 1. Opis projektu

Projekt przedstawia prosty system alarmowy wykonany na płytce Arduino Uno R3. Jego zadaniem jest wykrywanie ruchu za pomocą czujnika PIR i uruchamianie alarmu dźwiękowego.

System można włączyć za pomocą klawiatury membranowej 4x4. Po uruchomieniu rozpoczyna się 5-sekundowe uzbrajanie alarmu. Po tym czasie system zaczyna wykrywać ruch.

## 2. Wykorzystane elementy

- Arduino Uno R3 – steruje całym systemem.
- Czujnik PIR – wykrywa ruch.
- Klawiatura membranowa 4x4 – służy do uruchamiania alarmu.
- Buzzer – odpowiada za sygnał dźwiękowy.
- Czerwona dioda LED – informuje o wykryciu ruchu.
- Zielona dioda LED – informuje o uzbrojeniu systemu.
- Żółta dioda LED – informuje o uzbrajaniu systemu.
- Rezystory 220 Ω – ograniczają prąd przepływający przez diody.

## 3. Podłączenie elementów

| Element | Pin Arduino |
|---|---|
| Buzzer (+) | D10 |
| Czujnik PIR OUT | D9 |
| Czerwona dioda | D11 |
| Zielona dioda | D12 |
| Żółta dioda | D13 |
| Klawiatura R1 | D1 |
| Klawiatura R2 | D2 |
| Klawiatura R3 | D3 |
| Klawiatura R4 | D4 |
| Klawiatura C1 | D5 |
| Klawiatura C2 | D6 |
| Klawiatura C3 | D7 |
| Klawiatura C4 | D8 |

Dodatkowo:
- PIR VCC → 5V.
- PIR GND → GND.
- Buzzer (-) → GND.
- Krótsze nóżki diod LED → GND (przez odpowiednie połączenie na płytce).
- Każda dioda LED posiada osobny rezystor 220 Ω.

## 4. Zasada działania programu

Program działa w trzech głównych stanach:

### Stan 1 – Uzbrajanie systemu

Po naciśnięciu przycisku `#` na klawiaturze system rozpoczyna uzbrajanie. Zapala się żółta dioda LED. Proces trwa 5 sekund.

### Stan 2 – System uzbrojony

Po upływie 5 sekund żółta dioda gaśnie, a zapala się zielona. System jest gotowy do wykrywania ruchu. Czujnik PIR cały czas sprawdza, czy w jego zasięgu pojawił się ruch.

### Stan 3 – Alarm

Gdy czujnik PIR wykryje ruch, zapala się czerwona dioda LED i uruchamia się buzzer. Gdy czujnik przestanie wykrywać ruch, buzzer zostaje wyłączony, a system wraca do stanu uzbrojonego.

## 5. Najważniejsze funkcje programu

- `setup()` – konfiguruje piny Arduino i uruchamia komunikację szeregową.
- `loop()` – główna pętla programu, która cały czas sprawdza stan systemu.
- `keypad.getKey()` – odczytuje naciśnięty przycisk klawiatury.
- `millis()` – mierzy czas od uruchomienia Arduino. W programie służy do odliczenia 5 sekund uzbrajania.
- `digitalRead()` – odczytuje sygnał z czujnika PIR.
- `digitalWrite()` – włącza i wyłącza diody LED.
- `tone()` – uruchamia buzzer z częstotliwością 2000 Hz.
- `noTone()` – wyłącza sygnał dźwiękowy.
- `switch` – odpowiada za obsługę trzech stanów alarmu.

## 6. Uruchomienie projektu

1. Podłączyć wszystkie elementy do Arduino Uno R3.
2. Wgrać program do płytki Arduino.
3. Uruchomić symulację.
4. Nacisnąć przycisk `#` na klawiaturze.
5. Poczekać 5 sekund na uzbrojenie systemu.
6. Wywołać ruch przed czujnikiem PIR.
7. Sprawdzić działanie czerwonej diody LED i buzzera.

## 7. Podsumowanie

Projekt pokazuje, jak za pomocą Arduino można stworzyć prosty system alarmowy. Wykorzystuje czujnik ruchu, klawiaturę, diody LED i buzzer. Program został podzielony na trzy stany, dzięki czemu łatwiej kontrolować działanie alarmu i rozpoznawać jego aktualny tryb pracy.
