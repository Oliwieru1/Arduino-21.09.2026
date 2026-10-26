# Inteligentna Sygnalizacja Świetlna (2 Zestawy z Czujnikami Ruchu)

Projekt przedstawia system automatycznej sygnalizacji świetlnej sterowany za pomocą Arduino Uno. Układ monitoruje ruch w dwóch strefach za pomocą czujników PIR. W stanie spoczynku dla obu kierunków świeci się światło czerwone. Wykrycie ruchu w danej strefie powoduje automatyczną zmianę światła na zielone dla tej konkretnej strefy.

## 🚀 Jak to działa? (Logika programu)
1. **Stan początkowy:** Po uruchomieniu systemu obie sygnalizacje (Zestaw 1 i Zestaw 2) świecą się na **czerwono**.
2. **Wykrycie ruchu (Zbocze narastające - RISING):** Program reaguje tylko w momencie, gdy czujnik zmienia stan z braku ruchu (`LOW`) na wykrycie ruchu (`HIGH`).
3. **Zmiana świateł:** 
   * Jeśli ruch zostanie wykryty przez **Czujnik 1**, Zestaw 1 zmienia światło na **zielone** (czerwone gaśnie).
   * Jeśli ruch zostanie wykryty przez **Czujnik 2**, Zestaw 2 zmienia światło na **zielone** (czerwone gaśnie).
   * Druga strefa w tym czasie automatycznie otrzymuje (lub utrzymuje) światło czerwone, zapobiegając kolizji.

---

## 🛠️ Wykaz komponentów (BOM)
* **1x** Arduino Uno R3
* **2x** Czujnik ruchu PIR (np. Parallax PIR)
* **2x** Dioda LED (Czerwona)
* **2x** Dioda LED (Zielona)
* **4x** Rezystor (Zalecane 220 Ω do obsługi diod LED)
* Przewody połączeniowe

---

## 🔌 Schemat podłączenia pinów

### 1. Diody LED (Sygnalizatory)

| Komponent | Pin Arduino | Opis |
| :--- | :---: | :--- |
| **Zielona LED 1** | `8` | Zestaw górny – światło zielone |
| **Czerwona LED 1** | `9` | Zestaw górny – światło czerwone |
| **Zielona LED 2** | `10` | Zestaw dolny – światło zielone |
| **Czerwona LED 2** | `11` | Zestaw dolny – światło czerwone |

*Każda dioda podłączona jest dłuższą nóżką (anodą) do odpowiedniego pinu Arduino, a krótszą nóżką (katodą) przez rezystor do wspólnej linii masy (**GND**).*

### 2. Czujniki ruchu PIR

| Komponent | Pin Arduino | Opis |
| :--- | :---: | :--- |
| **Czujnik PIR 1** | `2` | Detekcja ruchu dla Zestawu 1 |
| **Czujnik PIR 2** | `3` | Detekcja ruchu dla Zestawu 2 |

*Czujniki wymagają również standardowego podpięcia zasilania pod piny **5V** oraz **GND** na płytce Arduino.*

---

## 💻 Instrukcja uruchomienia
1. Otwórz swój projekt w środowisku **Tinkercad Circuits**.
2. Upewnij się, że okablowanie odpowiada powyższej tabeli pinów.
3. Kliknij przycisk **Kod (Code)**, wybierz tryb tekstowy i wklej zawartość pliku `.ino`.
4. Kliknij **Rozpocznij symulację (Start Simulation)**.
5. Kliknij na wybrany czujnik PIR i poruszaj wirtualnym obiektem w polu jego widzenia, aby przetestować zmianę świateł.
