Kalkulator Arduino z klawiaturą 4x4 i wyświetlaczem LCD 16x2
1. Opis projektu

Projekt przedstawia prosty kalkulator wykonany przy użyciu płytki Arduino, klawiatury membranowej 4x4 oraz wyświetlacza LCD 16x2.

Urządzenie umożliwia wykonywanie podstawowych działań matematycznych: dodawania, odejmowania, mnożenia i dzielenia. Wynik obliczeń jest wyświetlany na ekranie LCD.

2. Wykorzystane elementy
Arduino (np. Arduino Uno)
Wyświetlacz LCD 16x2 z modułem I2C
Klawiatura membranowa 4x4
Przewody połączeniowe
Płytka stykowa
3. Wykorzystane biblioteki

Projekt wykorzystuje następujące biblioteki:

Adafruit_LiquidCrystal.h – obsługa wyświetlacza LCD.
Keypad.h – obsługa klawiatury membranowej 4x4.
4. Podłączenie elementów
Klawiatura 4x4
Pin klawiatury	Pin Arduino
R1	2
R2	3
R3	4
R4	5
C1	6
C2	7
C3	8
C4	9
Wyświetlacz LCD

Wyświetlacz LCD jest obsługiwany przez bibliotekę Adafruit_LiquidCrystal i korzysta z magistrali I2C.

5. Obsługa kalkulatora

Klawiatura posiada następujące funkcje:

Klawisz	Funkcja
0–9	Wprowadzanie cyfr
A	Dodawanie (+)
B	Odejmowanie (-)
C	Mnożenie (*)
D	Dzielenie (/)
#	Obliczenie wyniku
*	Reset kalkulatora
6. Zasada działania programu
Użytkownik wprowadza pierwszą liczbę za pomocą klawiatury.
Wybiera działanie matematyczne przyciskiem A, B, C lub D.
Wprowadza drugą liczbę.
Naciska przycisk #, aby wykonać obliczenie.
Wynik zostaje wyświetlony na ekranie LCD.
Przycisk * pozwala wyzerować kalkulator i rozpocząć nowe obliczenie.
7. Zabezpieczenia i ograniczenia
Program sprawdza, czy użytkownik nie próbuje dzielić przez zero.
W przypadku dzielenia przez zero wyświetlany jest komunikat o błędzie.
Każda liczba może zawierać maksymalnie 7 cyfr.
Wyniki prezentowane są z dokładnością do dwóch miejsc po przecinku.
Kalkulator obsługuje liczby całkowite wprowadzane z klawiatury, a wynik może być liczbą dziesiętną.
8. Uruchomienie projektu
Podłącz wszystkie elementy zgodnie z tabelą połączeń.
Zainstaluj wymagane biblioteki w Arduino IDE.
Otwórz plik z kodem programu.
Wybierz odpowiednią płytkę Arduino i port COM.
Wgraj program do Arduino.
Po uruchomieniu można korzystać z kalkulatora.
9. Podsumowanie

Projekt pozwala zapoznać się z obsługą klawiatury membranowej, wyświetlacza LCD oraz programowaniem mikrokontrolera Arduino. Pokazuje również praktyczne zastosowanie instrukcji warunkowych, zmiennych, funkcji oraz wykonywania operacji matematycznych.
