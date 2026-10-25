#pragma once
#include "Product.h"

// Категория: Чайный лист
class TeaLeaf : public Product {
public:
    TeaLeaf(std::string n, int p, int q, double w, std::string cat) 
        : Product(n, p, q, w, cat) {}
};

class GreenTea : public TeaLeaf {
public:
    GreenTea(std::string n, int p, int q, double w) : TeaLeaf(n, p, q, w, "tea_leaf") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<GreenTea>(*this); }
    void print() const override { 
        std::cout << "[Зеленый чай] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};

class Puer : public TeaLeaf {
public:
    Puer(std::string n, int p, int q, double w) : TeaLeaf(n, p, q, w, "tea_leaf") {}
    std::unique_ptr<Product> clone() const override { return std::make_unique<Puer>(*this); }
    void print() const override { 
        std::cout << "[Пуэр] ID: " << id 
                  << " | " << name 
                  << " | Цена: " << price.getValue() 
                  << " | Кол-во: " << quantity.getValue() 
                  << " | Вес: " << weight.getValue() << " кг\n"; 
    }
};