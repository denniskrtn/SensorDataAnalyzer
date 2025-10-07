#pragma once
#include <string>
#include <random>

class Sensor {
public:
    explicit Sensor(std::string name);
    double getReading();

private:
    std::string name;
    std::mt19937 gen;
    std::uniform_real_distribution<double> dist;
};