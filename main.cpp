#include <iostream>
#include <memory>
#include "Warehouse.h"
#include "ProductFactory.h"
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    std::cout << "Лабораторная работа 1: Чайная Фабрика\n\n";

    std::cout << "Сценарий 1: Создание склада и добавление товаров\n";
    Warehouse warehouse1(5);

    GreenTeaFactory greenTeaFactory;
    PuerFactory puerFactory;
    TeapotFactory teapotFactory;

    try {
        // Создаем элитные сорта чая и посуду
        warehouse1.addProduct(greenTeaFactory.createProduct(0, "Лун Цзин (Колодец Дракона)", 1500, 20, 0.1));
        warehouse1.addProduct(puerFactory.createProduct(0, "Шу Пуэр 'Золотая смола' 2015", 3000, 10, 0.35));
        warehouse1.addProduct(teapotFactory.createProduct(0, "Исинский чайник из глины", 4500, 3, 0.4));
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << "\n";
    }

    std::cout << "Товары на Складе 1:\n";
    for (auto it = warehouse1.begin(); it != warehouse1.end(); ++it) {
        (*it)->print();
    }

    std::cout << "\nСценарий 2: Глубокое копирование склада\n";
    Warehouse warehouse2 = warehouse1;
    std::cout << "Склад 2 (копия) создан.\n";
    
    // Ищем Пуэр по ID (он был добавлен вторым, значит его ID = 2)
    Product* p = warehouse2.findById(2);
    if (p) {
        p->setPrice(Price(2800)); // Делаем скидку на Пуэр в копии
        p->changeQuantity(-2);    // Продаем 2 штуки
        std::cout << "Изменён товар (Пуэр) на Складе 2.\n";
    }

    std::cout << "Склад 1 (Оригинал) ID 2: ";
    warehouse1.findById(2)->print();
    std::cout << "Склад 2 (Копия) ID 2: ";
    warehouse2.findById(2)->print();

    std::cout << "\nСценарий 3: Перемещение склада\n";
    Warehouse warehouse3 = std::move(warehouse1);
    std::cout << "Содержимое Склада 3 (перемещённого):\n";
    for (const auto& prod : warehouse3) {
        prod->print();
    }

    std::cout << "\nСценарий 4: Поиск и удаление \n";
    auto teas = warehouse3.findByCategory("tea_leaf");
    std::cout << "Найдено сортов чая: " << teas.size() << "\n";
    
    // Удаляем чайник (он был третьим, ID = 3)
    warehouse3.removeById(3);
    std::cout << "После удаления чайника (ID 3):\n";
    for (const auto& prod : warehouse3) {
        prod->print();
    }

    std::cout << "\nСценарий 5: Перемещение товара между складами\n";
    Warehouse warehouse4(10);
    Product* prodToTransfer = warehouse3.findById(2); // Берем Пуэр
    if (prodToTransfer) {
        prodToTransfer->transferTo(warehouse4);
    }
    
    std::cout << "Содержимое Склада 4 после перемещения:\n";
    for (const auto& prod : warehouse4) {
        prod->print();
    }

    std::cout << "\nКонец\n";
    return 0;
}