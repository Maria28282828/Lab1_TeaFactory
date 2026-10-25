#pragma once
#include <stdexcept>

class Quantity {
    int value;
public:
    Quantity(int val) : value(val) { if (val < 0) throw std::invalid_argument("Quantity cannot be negative"); }
    int getValue() const { return value; }
    void setValue(int newVal) { if (newVal < 0) throw std::invalid_argument("Quantity cannot be negative"); value = newVal; }
    void change(int delta) { if (value + delta < 0) throw std::invalid_argument("Quantity cannot be negative"); value += delta; }
};