#pragma once
#include <vector>
#include <string>
#include <optional>

struct Stats {
    size_t count;
    double average;
    double min;
    double max;
};

class Analyzer {
public:
    void addReading(double value);
    bool saveToFile(const std::string& path) const;
    std::optional<Stats> getStats() const;
    void printStats() const;

private:
    std::vector<double> readings;
};
