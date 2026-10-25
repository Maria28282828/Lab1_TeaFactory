#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>
#include <iostream>
#include "Product.h"

class Warehouse {
    std::vector<std::unique_ptr<Product>> products;
    size_t maxSize;

public:
    Warehouse(size_t maxSz) : maxSize(maxSz) {}
    
    Warehouse(const Warehouse& other);
    Warehouse& operator=(const Warehouse& other);
    Warehouse(Warehouse&& other) noexcept;
    Warehouse& operator=(Warehouse&& other) noexcept;
    ~Warehouse() = default;

    void addProduct(std::unique_ptr<Product> product);
    void removeById(int id);
    void removeByIndex(size_t index);
    
    Product* findById(int id);
    std::vector<Product*> findByCategory(const std::string& category);
    std::vector<Product*> findByPrice(const Price& price);

    class Iterator {
        std::vector<std::unique_ptr<Product>>::iterator current;
        std::vector<std::unique_ptr<Product>>::iterator end;
    public:
        Iterator(std::vector<std::unique_ptr<Product>>::iterator cur, std::vector<std::unique_ptr<Product>>::iterator e) 
            : current(cur), end(e) {}

        Product* operator*() { return current->get(); }
        Iterator& operator++() { ++current; return *this; }
        bool operator!=(const Iterator& other) const { return current != other.current; }
        bool operator==(const Iterator& other) const { return current == other.current; }
    };

    Iterator begin() { return Iterator(products.begin(), products.end()); }
    Iterator end() { return Iterator(products.end(), products.end()); }
    
    class ConstIterator {
        std::vector<std::unique_ptr<Product>>::const_iterator current;
    public:
        ConstIterator(std::vector<std::unique_ptr<Product>>::const_iterator cur) : current(cur) {}
        const Product* operator*() const { return current->get(); }
        ConstIterator& operator++() { ++current; return *this; }
        bool operator!=(const ConstIterator& other) const { return current != other.current; }
    };
    ConstIterator begin() const { return ConstIterator(products.begin()); }
    ConstIterator end() const { return ConstIterator(products.end()); }
};