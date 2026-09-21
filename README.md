Sygnalizacja Świetlna na Arduino
Projekt dwukierunkowej sygnalizacji świetlnej (lub sygnalizacji dla dwóch kierunków ruchu/pieszych) zrealizowany przy użyciu płytki Arduino. Program steruje czterema diodami LED reprezentującymi światła czerwone oraz zielone dla dwóch niezależnych torów.
📋 Opis Działania
Program realizuje cykl świetlny o łącznym czasie trwania 12 sekund, podzielony na 4 fazy:
0 – 4 s (Faza 1): Światło czerwone i zielone dla pierwszego kierunku (Pin 9 i Pin 10). Drugi kierunek wyłączony.
4 – 6 s (Faza 2 - Przejściowa): Światła czerwone dla obu kierunków (Pin 9 oraz Pin 11) – zapewnienie bezpiecznego czyszczenia skrzyżowania.
6 – 10 s (Faza 3): Światło czerwone i zielone dla drugiego kierunku (Pin 11 i Pin 12). Pierwszy kierunek wyłączony.
10 – 12 s (Faza 4 - Przejściowa): Ponowne światła czerwone dla obu kierunków (Pin 9 oraz Pin 11).
Po upływie 12 sekund cykl powtarza się automatycznie dzięki zastosowaniu operacji modulo (millis() % 12000).
🛠️ Schemat Podłączenia (Hardware)
Wymagane Elementy:
1x Arduino (np. Uno, Nano, Mega)
4x Dioda LED (2x Czerwona, 2x Zielona)
4x Rezystor (np. 220Ω lub 330Ω)
Płytka stykowa i przewody połączeniowe
Przypisanie Pinów:
Element
Pin Arduino
Opis
Dioda LED 1
Pin 9
Czerwone (Kierunek 1)
Dioda LED 2
Pin 10
Zielone (Kierunek 1)
Dioda LED 3
Pin 11
Czerwone (Kierunek 2)
Dioda LED 4
Pin 12
Zielone (Kierunek 2)
