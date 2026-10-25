
🛠️ Mapowanie Pinów i Kierunków

Kolejność obsługi kierunków w programie:
0 = GÓRNY, 1 = PRAWY (Zablokowany), 2 = DOLNY, 3 = LEWY

Diody LED (Wyjścia)


Kierunek	Indeks	Pin LED Czerwona	Pin LED Zielona	Status działania
GÓRNY	0	9	8	🟢 Sprawny
PRAWY	1	7	6	🔴 Odcięty programowo
DOLNY	2	5	2	🟢 Sprawny
LEWY	3	3	4	🟢 Sprawny


Czujniki Ruchu (Wejścia)

Wszystkie piny wejściowe pracują w trybie INPUT_PULLUP.
• Pin 12: Czujnik Górny
• Pin 10: Czujnik Dolny
• Pin 13: Czujnik Lewy (Dodatkowo zabezpieczony warunkiem zależności od pinu 12)
• Pin 11: Wolny / Nieaktywny (przypisany sprzętowo do uszkodzonego kierunku prawego)

⚙️ Algorytm i Logika Działania

1. Detekcja zbocza narastającego: Pojazdy są dodawane do kolejki tylko w momencie wykrycia nowego ruchu (ruch[i] && !poprzedniRuch[i]). Zapobiega to ciągłemu dodawaniu tego samego pojazdu do ogonka.
2. Kolejkowanie FIFO: Auta ze sprawnych kierunków ustawiają się w cyklicznym buforze. Zielone światło otrzymuje zawsze ten kierunek, który zgłosił się jako pierwszy.
3. Czas podtrzymania (5000 ms): Po opuszczeniu czujnika przez pojazd, zielone światło świeci się jeszcze przez 5 sekund (czasPodtrzymania). Jeśli w tym czasie pojawi się kolejny pojazd na tym samym kierunku, licznik czasu resetuje się, umożliwiając płynny przejazd kolumny samochodów.

🚀 Instrukcja Wdrożenia

1. Podłącz diody LED oraz przyciski/czujniki do płytki Arduino zgodnie z powyższą tabelą mapowania pinów.
2. Upewnij się, że przyciski/czujniki zwierają pin wejściowy do masy (GND) w momencie wykrycia pojazdu (stan LOW w spoczynku, stan HIGH przy detekcji – zgodnie z logiką kodu).
3. Wgraj program na płytkę za pomocą Arduino IDE.
