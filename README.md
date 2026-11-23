Automatyczna brama sterowana pilotem IR i czujnikiem ruchu PIR
1. Opis projektu

Projekt przedstawia system automatycznego sterowania bramą z wykorzystaniem dwóch serwomechanizmów, pilota na podczerwień (IR) oraz czujnika ruchu PIR.

Brama może być otwierana i zamykana za pomocą przycisku POWER na pilocie. Podczas ruchu bramy możliwe jest jej zatrzymanie, a następnie wznowienie ruchu w zapamiętanym kierunku.

Dodatkowo zastosowany czujnik PIR odpowiada za wykrywanie ruchu podczas zamykania bramy. Jeśli czujnik wykryje obecność obiektu, brama automatycznie zmieni kierunek ruchu i zacznie się otwierać.

Dioda LED sygnalizuje aktualny ruch bramy.

2. Wykorzystane komponenty
Arduino (np. Arduino Uno)
2 × serwomechanizm
Odbiornik podczerwieni IR
Pilot na podczerwień
Czujnik ruchu PIR
Dioda LED
Przewody połączeniowe
Płytka stykowa
3. Podłączenie elementów
Element	Pin Arduino
Serwomechanizm 1	D3
Serwomechanizm 2	D5
Odbiornik IR	D10
Dioda LED	D12
Czujnik PIR	D4

Zasilanie:

Wszystkie elementy należy zasilić odpowiednim napięciem zgodnym z ich specyfikacją.
Przy zasilaniu serwomechanizmów z zewnętrznego źródła należy połączyć masę zasilacza z GND Arduino.
Nie należy przeciążać stabilizatora ani pinu 5 V Arduino serwomechanizmami.
4. Zasada działania

System wykorzystuje pięć stanów pracy:

Stan	Opis
STAN_ZAMKNIETA	Brama jest zamknięta.
STAN_OTWARTA	Brama jest otwarta.
STAN_OTWIERANIE	Brama aktualnie się otwiera.
STAN_ZAMYKANIE	Brama aktualnie się zamyka.
STAN_ZATRZYMANIE	Brama została zatrzymana podczas ruchu.
Sterowanie pilotem IR

Przycisk POWER odpowiada za zmianę stanu bramy:

Gdy brama jest zamknięta – rozpoczęcie otwierania.
Gdy brama jest otwarta – rozpoczęcie zamykania.
Gdy brama się otwiera lub zamyka – zatrzymanie ruchu.
Gdy brama jest zatrzymana – wznowienie ruchu w zapamiętanym kierunku.

Dodatkowo zastosowano zabezpieczenie przed wielokrotnym odczytaniem tego samego przycisku. Kolejne polecenie może zostać wykonane po upływie 300 ms.

Działanie czujnika PIR

Czujnik PIR monitoruje otoczenie podczas zamykania bramy.

Jeśli zostanie wykryty ruch:

System odczytuje sygnał HIGH z czujnika.
Aktualny proces zamykania zostaje przerwany.
Kierunek ruchu zostaje zmieniony.
Brama rozpoczyna automatyczne otwieranie.

Czujnik PIR nie wpływa na działanie bramy w pozostałych stanach.

Sterowanie serwomechanizmami

Zastosowano dwa serwomechanizmy, które poruszają się jednocześnie w przeciwnych kierunkach.

Położenie	Serwo 1	Serwo 2
Brama zamknięta	0°	180°
Brama otwarta	90°	90°

Ruch serwomechanizmów odbywa się stopniowo, co 15 ms, o jeden stopień kąta. Dzięki temu brama porusza się płynnie.

Sygnalizacja LED

Dioda LED podłączona do pinu D12 informuje o aktualnym ruchu bramy:

LED świeci – brama jest w ruchu.
LED nie świeci – brama jest zatrzymana lub osiągnęła położenie końcowe.
5. Wykorzystane biblioteki

Projekt korzysta z następujących bibliotek:

Servo.h – umożliwia sterowanie serwomechanizmami.
IRremote.hpp – umożliwia odbieranie i dekodowanie sygnałów z pilota IR.

Bibliotekę IRremote można zainstalować za pomocą Arduino IDE:

Otwórz Arduino IDE.
Przejdź do Library Manager.
Wyszukaj bibliotekę IRremote.
Zainstaluj bibliotekę.

Biblioteka Servo jest standardowo dostępna w Arduino IDE.

6. Uruchomienie projektu
Podłącz wszystkie komponenty zgodnie ze schematem połączeń.
Zainstaluj wymagane biblioteki.
Otwórz kod programu w Arduino IDE.
Wybierz odpowiednią płytkę Arduino oraz port COM.
Wgraj program do mikrokontrolera.
Otwórz Monitor portu szeregowego z prędkością 9600 baud.
Skieruj pilot IR w stronę odbiornika i naciśnij przycisk POWER.

Po uruchomieniu system wyświetli komunikat:

SYSTEM GOTOWY

7. Komunikaty w Monitorze portu szeregowego

Program wyświetla komunikaty informujące o najważniejszych zdarzeniach:

Komunikat	Znaczenie
SYSTEM GOTOWY	System został uruchomiony.
RUCH WYKRYTY!	Czujnik PIR wykrył ruch.
ZAMIANA KIERUNKU NA OTWIERANIE!	Następuje zmiana kierunku ruchu bramy.
BRAMA OTWARTA	Brama osiągnęła pozycję otwartą.
BRAMA ZAMKNIETA	Brama osiągnęła pozycję zamkniętą.
8. Możliwości projektu
Sterowanie bramą za pomocą pilota IR.
Płynne otwieranie i zamykanie.
Zatrzymywanie bramy w dowolnym momencie.
Wznawianie ruchu w zapamiętanym kierunku.
Automatyczna zmiana kierunku podczas wykrycia ruchu przez PIR.
Sygnalizacja ruchu za pomocą diody LED.
Obsługa systemu oparta na maszynie stanów.
9. Podsumowanie

Projekt prezentuje prosty system automatycznego sterowania bramą oparty na mikrokontrolerze Arduino.

Połączenie sterowania pilotem IR z czujnikiem ruchu PIR pozwala na wygodną obsługę oraz automatyczną reakcję na wykrycie przeszkody lub ruchu podczas zamykania.

Program wykorzystuje maszynę stanów, dzięki czemu poszczególne tryby pracy bramy są uporządkowane i łatwe do rozbudowy.

Uwaga: Czujnik PIR wykrywa ruch, a nie fizyczną obecność wszystkich przeszkód. W rzeczywistej bramie należy zastosować odpowiednie zabezpieczenia, np. fotokomórki i mechanizm awaryjnego zatrzymania.
