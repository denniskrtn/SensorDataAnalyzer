#include "Analyzer.h"
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>

void Analyzer::addReading(double value) {
    readings.push_back(value);
}

void Analyzer::saveToFile(const std::string& path) {
    std::ofstream file(path);
    if (!file.is_open()) {
        std::cerr << "Fehler: Datei konnte nicht geöffnet werden: " << path << "\n";
        return;
    }
    for (double val : readings) {
        file << val << "\n";
    }
    file.close();
}

void Analyzer::printStats() const {
    if (readings.empty()) {
        std::cout << "Keine Messwerte vorhanden.\n";
        return;
    }

    double sum = std::accumulate(readings.begin(), readings.end(), 0.0);
    double avg = sum / readings.size();
    double maxVal = *std::max_element(readings.begin(), readings.end());
    double minVal = *std::min_element(readings.begin(), readings.end());

    std::cout << "Statistik:\n";
    std::cout << " - Anzahl Werte: " << readings.size() << "\n";
    std::cout << " - Durchschnitt: " << avg << "\n";
    std::cout << " - Minimum: " << minVal << "\n";
    std::cout << " - Maximum: " << maxVal << "\n";
}
