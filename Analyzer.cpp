#include "Analyzer.h"
#include <fstream>
#include <iostream>
#include <numeric>
#include <algorithm>
#include <iomanip>
#include <cmath>

void Analyzer::addReading(double value) {
    if (std::isnan(value)) {
        std::cerr << "[Warnung] Ungültiger Messwert (NaN) ignoriert.\n";
        return;
    }
    readings.push_back(value);
}

bool Analyzer::saveToFile(const std::string& path) const {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "[Fehler] Datei konnte nicht geöffnet werden: " << path << "\n";
        return false;
    }

    file << std::fixed << std::setprecision(2);
    for (auto val : readings) {
        if (!(file << val << "\n")) {
            std::cerr << "[Fehler] Fehler beim Schreiben in Datei: " << path << "\n";
            return false;
        }
    }

    return true;
}

std::optional<Stats> Analyzer::getStats() const {
    if (readings.empty()) return std::nullopt;

    double sum = std::accumulate(readings.cbegin(), readings.cend(), 0.0);
    return Stats{
        readings.size(),
        sum / readings.size(),
        *std::min_element(readings.cbegin(), readings.cend()),
        *std::max_element(readings.cbegin(), readings.cend())
    };
}

void Analyzer::printStats() const {
    if (readings.empty()) {
        std::cout << "Keine Messwerte vorhanden.\n";
        return;
    }

    auto statsOpt = getStats();
    if (!statsOpt) return;

    const Stats& stats = *statsOpt;

    std::cout << "\n=== Statistik ===\n";
    std::cout << "Anzahl Werte : " << stats.count << "\n";
    std::cout << "Durchschnitt : " << stats.average << " C\n";
    std::cout << "Minimum      : " << stats.min << " C\n";
    std::cout << "Maximum      : " << stats.max << " C\n";
    std::cout << "====================\n";
}
