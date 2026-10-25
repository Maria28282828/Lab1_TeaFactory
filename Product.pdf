#pragma once
#include <string>
#include <memory>
#include <iostream>
#include "Price.h"
#include "Quantity.h"
#include "Weight.h"

class Warehouse;

class Product {
protected:
    static int nextId;
    int id;
    std::string name;
    Price price;
    Quantity quantity;
    Weight weight;
    std::string category;

public:
    Product(std::string n, int p, int q, double w, std::string cat);
    virtual ~Product() = default;

    int getId() const { return id; }
    std::string getName() const { return name; }
    Price getPrice() const { return price; }
    Quantity getQuantity() const { return quantity; }
    Weight getWeight() const { return weight; }
    std::string getCategory() const { return category; }

    void setPrice(const Price& newPrice) { price = newPrice; }
    void changeQuantity(int delta) { quantity.change(delta); }

    void transferTo(Warehouse& other);
    
    virtual std::unique_ptr<Product> clone() const = 0;
    virtual void print() const = 0;
};

inline Product::Product(std::string n, int p, int q, double w, std::string cat)
    : id(nextId++), name(n), price(p), quantity(q), weight(w), category(cat) {}