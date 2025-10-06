#include "Sensor.h"
#include <cstdlib>
#include <ctime>

Sensor::Sensor(std::string name) : name(name) {
    srand(static_cast<unsigned>(time(nullptr)));
}

double Sensor::getReading() {
    return (rand() % 1000) / 10.0; // z.B. 0.0 bis 100.0
}