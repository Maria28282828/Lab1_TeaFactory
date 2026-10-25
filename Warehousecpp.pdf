#include "Warehouse.h"
int Product::nextId = 1;

Warehouse::Warehouse(const Warehouse& other) : maxSize(other.maxSize) {
    for (const auto& prod : other.products) {
        products.push_back(prod->clone());
    }
}

Warehouse& Warehouse::operator=(const Warehouse& other) {
    if (this != &other) {
        products.clear();
        maxSize = other.maxSize;
        for (const auto& prod : other.products) {
            products.push_back(prod->clone());
        }
    }
    return *this;
}

Warehouse::Warehouse(Warehouse&& other) noexcept 
    : products(std::move(other.products)), maxSize(other.maxSize) {}

Warehouse& Warehouse::operator=(Warehouse&& other) noexcept {
    if (this != &other) {
        products = std::move(other.products);
        maxSize = other.maxSize;
    }
    return *this;
}

void Warehouse::addProduct(std::unique_ptr<Product> product) {
    if (products.size() >= maxSize) {
        throw std::overflow_error("Склад переполнен!");
    }
    products.push_back(std::move(product));
}

void Warehouse::removeById(int id) {
    auto it = std::remove_if(products.begin(), products.end(), 
        [id](const std::unique_ptr<Product>& p) { return p->getId() == id; });
    if (it != products.end()) {
        products.erase(it, products.end());
    } else {
        std::cout << "Товар с ID " << id << " не найден.\n";
    }
}

void Warehouse::removeByIndex(size_t index) {
    if (index >= products.size()) throw std::out_of_range("Индекс вне диапазона");
    products.erase(products.begin() + index);
}

Product* Warehouse::findById(int id) {
    for (auto& p : products) {
        if (p->getId() == id) return p.get();
    }
    return nullptr;
}

std::vector<Product*> Warehouse::findByCategory(const std::string& category) {
    std::vector<Product*> result;
    for (auto& p : products) {
        if (p->getCategory() == category) result.push_back(p.get());
    }
    return result;
}

std::vector<Product*> Warehouse::findByPrice(const Price& price) {
    std::vector<Product*> result;
    for (auto& p : products) {
        if (p->getPrice().getValue() == price.getValue()) result.push_back(p.get());
    }
    return result;
}

void Product::transferTo(Warehouse& other) {
    other.addProduct(this->clone());
    std::cout << "Товар " << name << " перемещён на другой склад (клонирован).\n";
}