#pragma once
#include <string>

class Sensor {
private:
    std::string name;
public:
    Sensor(std::string name);
    double getReading();
};
