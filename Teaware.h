#pragma once
#include "Product.h"

// Категория: Посуда
class Teaware : public Product {
public:
    Teaware(std::string n, int p, int q, double w, std::string cat) 
        : Product(n, p, q, w, cat) {}
};

class Teapot : public Teaware {
public:
    Teapot(std::string n, int p, int q, double w) : Teaware(n, p, q, w, "teaware") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<Teapot>(*this); }
    void print() const override { 
        std::cout << "[Чайник] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};

class Cup : public Teaware {
public:
    Cup(std::string n, int p, int q, double w) : Teaware(n, p, q, w, "teaware") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<Cup>(*this); }
    void print() const override { 
        std::cout << "[Чашка] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};