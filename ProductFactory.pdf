#pragma once
#include <memory>
#include <string>
#include "Product.h"
#include "TeaLeaf.h"
#include "Teaware.h"
#include "Packaging.h"

class ProductFactory {
public:
    virtual std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) = 0;
    virtual ~ProductFactory() = default;
};

class GreenTeaFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<GreenTea>(name, price, qty, weight);
    }
};

class PuerFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<Puer>(name, price, qty, weight);
    }
};

class TeapotFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<Teapot>(name, price, qty, weight);
    }
};

class CupFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<Cup>(name, price, qty, weight);
    }
};

class BoxFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<Box>(name, price, qty, weight);
    }
};

class BagFactory : public ProductFactory {
public:
    std::unique_ptr<Product> createProduct(int id, const std::string& name, int price, int qty, double weight) override {
        return std::make_unique<Bag>(name, price, qty, weight);
    }
};