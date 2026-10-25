#pragma once
#include <stdexcept>

class Weight {
    double value;
public:
    Weight(double val) : value(val) { if (val < 0) throw std::invalid_argument("Weight cannot be negative"); }
    double getValue() const { return value; }
    void setValue(double newVal) { if (newVal < 0) throw std::invalid_argument("Weight cannot be negative"); value = newVal; }
};