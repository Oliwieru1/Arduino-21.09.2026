🚦 Sygnalizacja świetlna – Arduino
📋 Opis projektu

Projekt przedstawia prosty system sygnalizacji świetlnej dla 4 kierunków zrealizowany na platformie Arduino.

Układ obsługuje cztery kierunki:

🟢 Góra

🟢 Prawo

🟢 Dół

🟢 Lewo

Dla każdego kierunku dostępne są dwie diody LED:

🔴 czerwona

🟢 zielona

Program automatycznie zmienia światła w określonych odstępach czasu, tworząc cykl przypominający działanie skrzyżowania.

⚙️ Zasada działania

Program wykorzystuje funkcję millis() do odmierzania czasu. Dzięki temu nie jest używana funkcja delay(), a Arduino może wykonywać inne operacje podczas oczekiwania.

Cykl działania składa się z dwóch faz:

1. 🔴 Wszystkie światła czerwone

Przez 2 sekundy na wszystkich czterech kierunkach świecą czerwone diody.

Jest to faza przejściowa pomiędzy zmianą kierunku ruchu.

2. 🟢 Jeden kierunek ma zielone

Przez 4 sekundy:

jeden wybrany kierunek ma światło zielone,

pozostałe trzy kierunki mają światło czerwone.

Po upływie 4 sekund program przełącza się ponownie na wszystkie czerwone światła i wybiera następny kierunek.

Kierunki zmieniają się zgodnie z ruchem wskazówek zegara:

Góra → Prawo → Dół → Lewo → Góra → ...

🔌 Podłączenie pinów
Kierunek	🔴 Czerwona LED	🟢 Zielona LED
Góra	Pin 2	Pin 3
Prawo	Pin 4	Pin 5
Dół	Pin 6	Pin 7
Lewo	Pin 8	Pin 9

Każda dioda LED powinna być podłączona przez odpowiedni rezystor ograniczający prąd.

🧠 Najważniejsze elementy programu
Tablice pinów

Piny diod są przechowywane w dwóch tablicach:

const int pinyCzerwone[] = {
  CZERWONA_GORNA,
  CZERWONA_PRAWA,
  CZERWONA_DOLNA,
  CZERWONA_LEWA
};

const int pinyZielone[] = {
  ZIELONA_GORNA,
  ZIELONA_PRAWA,
  ZIELONA_DOLNA,
  ZIELONA_LEWA
};


Dzięki temu można łatwo sterować wszystkimi światłami za pomocą pętli for.

Funkcja ustawSwiatla()

Funkcja odpowiada za ustawienie odpowiedniego stanu wszystkich diod.

ustawSwiatla(-1);


oznacza włączenie czerwonego światła na wszystkich kierunkach.

Natomiast:

ustawSwiatla(aktualnyKierunek);


włącza zielone światło na wybranym kierunku oraz czerwone na pozostałych.

Zmiana kierunku

Po zakończeniu fazy zielonego światła kierunek jest zwiększany:

aktualnyKierunek = (aktualnyKierunek + 1) % 4;


Operator % 4 powoduje, że po kierunku Lewo program wraca ponownie do kierunku Góra.

⏱️ Harmonogram
Faza	Czas	Stan świateł
Wszystkie czerwone	2 s	🔴 🔴 🔴 🔴
Góra zielona	4 s	🟢 🔴 🔴 🔴
Wszystkie czerwone	2 s	🔴 🔴 🔴 🔴
Prawo zielone	4 s	🔴 🟢 🔴 🔴
Wszystkie czerwone	2 s	🔴 🔴 🔴 🔴
Dół zielony	4 s	🔴 🔴 🟢 🔴
Wszystkie czerwone	2 s	🔴 🔴 🔴 🔴
Lewo zielone	4 s	🔴 🔴 🔴 🟢

Po zakończeniu cyklu wszystko zaczyna się od początku.

💻 Wykorzystane technologie

Arduino

C/C++

diody LED czerwone i zielone

rezystory ograniczające prąd

funkcja millis() do obsługi czasu

🎯 Cel projektu

Celem projektu jest zaprezentowanie podstaw:

sterowania diodami LED,

korzystania z tablic i pętli for,

tworzenia funkcji sterujących,

obsługi wielu stanów programu,

odmierzania czasu za pomocą millis(),

tworzenia prostego automatu stanów.

🚀 Możliwe rozszerzenia

Projekt można rozbudować między innymi o:

🟡 żółte światła,

🚶 sygnalizację dla pieszych,

przyciski dla pieszych,

czujniki ruchu,

wyświetlacz pokazujący czas pozostały do zmiany światła,

regulację czasu świecenia,

tryb nocny,

sygnalizację dźwiękową,

czujniki wykrywające pojazdy.

📄 Licencja

Projekt może być dowolnie wykorzystywany i modyfikowany w celach edukacyjnych.
