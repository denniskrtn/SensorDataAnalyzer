#pragma once
#include <vector>
#include <string>

class Analyzer {
private:
    std::vector<double> readings;

public:
    void addReading(double value);
    void saveToFile(const std::string& path);
    void printStats() const;
};
