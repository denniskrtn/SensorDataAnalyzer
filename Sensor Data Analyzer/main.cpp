#include <iostream>
#include <iomanip>
#include <thread>
#include <chrono>
#include <filesystem>
#include "Sensor.h"
#include "Analyzer.h"

int main() {
    std::cout << std::unitbuf;
    std::cout << "=== Temperaturmessung gestartet ===\n";

    Sensor sensor("TemperatureSensor");
    Analyzer analyzer;

    constexpr int numReadings = 10;

    std::cout << "Messwerte:\n";
    std::cout << "Idx | Wert (C)\n";
    std::cout << "----+---------\n";

    for (int i = 0; i < numReadings; ++i) {
        double reading = sensor.getReading();
        analyzer.addReading(reading);

        std::cout << std::setw(3) << i + 1 << " | "
            << std::fixed << std::setprecision(2)
            << std::setw(7) << reading << " C\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::filesystem::create_directories("data");
    if (analyzer.saveToFile("data/readings.txt")) {
        std::cout << "\nDaten wurden in 'data/readings.txt' gespeichert.\n";
    }

    analyzer.printStats();

    std::cout << "=== Messung abgeschlossen ===\n";

    return 0;
}
