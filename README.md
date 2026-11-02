🌯 ROLLO KEBAB – NA ZAMKOWEJ!
📟 Opis projektu

Projekt wykorzystuje wyświetlacz LCD 16x2 sterowany za pomocą biblioteki Adafruit_LiquidCrystal.

Urządzenie wyświetla serię humorystycznych haseł promujących ROLLO KEBAB. Komunikaty zmieniają się automatycznie co 3,5 sekundy, tworząc niepowtarzalny klimat TRUE ADAM VIBE!

🛠️ Wykorzystane komponenty
Arduino
Wyświetlacz LCD 16x2
Biblioteka Adafruit_LiquidCrystal
Przewody połączeniowe
📚 Wykorzystane technologie
C++ (Arduino)
Arduino IDE
Biblioteka Adafruit LiquidCrystal
⚙️ Jak działa projekt?
Arduino inicjalizuje wyświetlacz LCD 16x2.
Włącza podświetlenie ekranu.
Wywołuje funkcję pokaz(), która wyświetla dwa wiersze tekstu.
Każdy komunikat pozostaje na ekranie przez 3500 ms.
Po wyświetleniu wszystkich haseł cykl rozpoczyna się od początku.
💻 Funkcja pokaz()
cpp
void pokaz(String gora, String dol)
{
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print(gora);
  lcd_1.setCursor(0, 1);
  lcd_1.print(dol);
  delay(3500);
}


Funkcja odpowiada za:

Czyszczenie wyświetlacza.
Ustawienie kursora w pierwszym wierszu.
Wyświetlenie górnego tekstu.
Ustawienie kursora w drugim wierszu.
Wyświetlenie dolnego tekstu.
Odczekanie 3,5 sekundy.
🔥 Wyświetlane hasła
ROLLO KEBAB – NA ZAMKOWEJ!
ROLLO = TRUE – ADAM!
INNE KEBABY – TO SUB3!
ROLLO MA MOC – INNI NIE MAJA!
TRUE ADAM VIBE – TYLKO W ROLLO!
INNE KEBABY? – TOTALNE SUB3!
ROLLO KEBAB – ABSOLUTNY TOP!
NIE BADZ SUB3 – WYBIERZ ROLLO!
ROLLO = GOAT – ZAMKOWA!
🚀 Uruchomienie projektu
Otwórz projekt w Arduino IDE.
Zainstaluj bibliotekę Adafruit_LiquidCrystal.
Podłącz wyświetlacz LCD.
Wybierz odpowiednią płytkę Arduino i port COM.
Wgraj program na płytkę.
Obserwuj, jak ROLLO przejmuje wyświetlacz!
🏆 Podsumowanie

To nie jest zwykły wyświetlacz LCD.

To oficjalny system propagandy ROLLO KEBAB.

ROLLO = TRUE. INNE KEBABY = SUB3.

🌯 NA ZAMKOWEJ ROLLO MA MOC!
