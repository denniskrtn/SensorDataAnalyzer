# Temperaturmessung (C++)

![C++](https://img.shields.io/badge/C%2B%2B-17-blue)
![MIT License](https://img.shields.io/badge/License-MIT-green)

Dieses Projekt simuliert eine einfache Temperaturmessung mit einem Sensor und analysiert die Messwerte.
Es zeigt, wie man:

- Zufällige Messwerte generiert (Simulation eines Sensors)
- Messwerte live in der Konsole anzeigt
- Statistiken berechnet (Durchschnitt, Minimum, Maximum)
- Messwerte in eine Datei speichert

---

## Projektstruktur
```text
Sensor Data Analyzer/
├── Headerdateien/
│   ├── Sensor.h
│   └── Analyzer.h
├── Quelldateien/
│   ├── main.cpp
│   ├── Sensor.cpp
│   └── Analyzer.cpp
├── data/         # Messwerte
├── README.md
├── .gitignore
└── Sensor Data Analyzer.vcxproj

```

---

## Nutzung

### 1. Repository klonen
Klonen Sie das Projekt von GitHub:
```bash
git clone https://github.com/denniskrtn/SensorDataAnalyzer.git
```
### 2. Projekt öffnen
- Öffnen Sie Visual Studio -> File -> Open -> Project/Solution
- Wähle SensorDataAnalyzer.sln im geklonten Ordner aus.

### 3. Kompilieren und Ausführen
- Build -> Start
- Das Programm zeigt die Temperaturmesswerte in der Konsole an.

---

## Beispiel
```text
=== Temperaturmessung gestartet ===
Messwerte:
Idx | Wert (C)
----+---------
  1 |   12.34 C
  2 |    5.67 C
  3 |   22.89 C
  ...
Daten wurden in 'data/readings.txt' gespeichert.

=== Statistik ===
Anzahl Werte : 10
Durchschnitt : 15.23 C
Minimum      :  5.67 C
Maximum      : 22.89 C
====================
=== Messung abgeschlossen ===
```

---

## Messwerte
- Die Messwerte werden automatisch in data/readings.txt gespeichert.
- Jeder Messwert steht in einer eigenen Zeile mit zwei Nachkommastellen.

---

## Features
- Live-Anzeige der Messwerte in der Konsole.
- Zufällige Temperatursimulation zwischen -10 °C und 40 °C
- Berechnung von Anzahl, Durchschnitt, Minimum und Maximum.
- Sicheres Schreiben in Datei mit Fehlerprüfung.

---

## Erweiterungen
- CSV-Ausgabe für einfache Weiterverarbeitung.
- Messwerte über Zeit aufzeichnen und grafisch darstellen.
- Integration echter Sensoren.
- Mehrere Sensoren gleichzeitig auswerten.

---

## Lizenz
MIT License
