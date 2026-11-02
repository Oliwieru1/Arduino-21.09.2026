
#include <Adafruit_LiquidCrystal.h>

Adafruit_LiquidCrystal lcd_1(0);

void pokaz(String gora, String dol)
{
  lcd_1.clear();
  lcd_1.setCursor(0, 0);
  lcd_1.print(gora);
  lcd_1.setCursor(0, 1);
  lcd_1.print(dol);
  delay(3500);
}

void setup()
{
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
}

void loop()
{
  pokaz("ROLLO KEBAB", "NA ZAMKOWEJ!");

  pokaz("ROLLO = TRUE", "ADAM!");

  pokaz("INNE KEBABY", "TO SUB3!");

  pokaz("ROLLO MA MOC", "INNI NIE MAJA!");

  pokaz("TRUE ADAM VIBE", "TYLKO W ROLLO!");

  pokaz("INNE KEBABY?", "TOTALNE SUB3!");

  pokaz("ROLLO KEBAB", "ABSOLUTNY TOP!");

  pokaz("NIE BADZ SUB3", "WYBIERZ ROLLO!");

  pokaz("ROLLO = GOAT", "ZAMKOWA!");
}
