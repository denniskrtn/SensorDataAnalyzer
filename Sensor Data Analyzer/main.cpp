#include <iostream>
#include "Sensor.h"
#include "Analyzer.h"

int main() {
    Sensor sensor("TemperatureSensor");
    Analyzer analyzer;

    // Simuliere 10 Messwerte
    for (int i = 0; i < 10; ++i) {
        double reading = sensor.getReading();
        analyzer.addReading(reading);
    }

    analyzer.saveToFile("data/readings.txt");
    analyzer.printStats();
    return 0;
}
