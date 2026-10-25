#pragma once
#include <stdexcept>

class Price {
    int value;
public:
    Price(int val) : value(val) { if (val < 0) throw std::invalid_argument("Price cannot be negative"); }
    int getValue() const { return value; }
    void setValue(int newVal) { if (newVal < 0) throw std::invalid_argument("Price cannot be negative"); value = newVal; }
};