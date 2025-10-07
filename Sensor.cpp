#include "Sensor.h"

Sensor::Sensor(std::string name)
    : name(std::move(name)),
    gen(std::random_device{}()),
    dist(-10.0, 40.0)
{
}

double Sensor::getReading() {
    return dist(gen);
}