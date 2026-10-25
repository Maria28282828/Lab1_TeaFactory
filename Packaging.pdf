#pragma once
#include "Product.h"

// Категория: Упаковка
class Packaging : public Product {
public:
    Packaging(std::string n, int p, int q, double w, std::string cat) 
        : Product(n, p, q, w, cat) {}
};

class Box : public Packaging {
public:
    Box(std::string n, int p, int q, double w) : Packaging(n, p, q, w, "packaging") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<Box>(*this); }
    void print() const override { 
        std::cout << "[Коробка] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};

class Bag : public Packaging {
public:
    Bag(std::string n, int p, int q, double w) : Packaging(n, p, q, w, "packaging") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<Bag>(*this); }
    void print() const override { 
        std::cout << "[Пакетик] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};