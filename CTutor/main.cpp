#include <iostream>
#include <string>
#include <Windows.h>

class ProductFactory {
public:
    virtual ~ProductFactory() {}
    virtual void createClothing(std::string type) = 0;
    virtual void createElectronics(std::string type) = 0;
};

class ClothingFactory : public ProductFactory {
public:
    void createClothing(std::string type) override {
        if (type == "футболка") {
            std::cout << "Створено футболку\n";
        }
        else if (type == "штани") {
            std::cout << "Створено штани\n";
        }
        else if (type == "куртка") {
            std::cout << "Створено куртку\n";
        }
        else {
            std::cout << "Такий тип одягу не підтримується\n";
        }
    }

    void createElectronics(std::string type) override {
        std::cout << "Фабрика одягу не може створити електроніку\n";
    }
};

class ElectronicsFactory : public ProductFactory {
public:
    void createClothing(std::string type) override {
        std::cout << "Фабрика електроніки не може створити одяг\n";
    }

    void createElectronics(std::string type) override {
        if (type == "смартфон") {
            std::cout << "Створено смартфон\n";
        }
        else if (type == "ноутбук") {
            std::cout << "Створено ноутбук\n";
        }
        else if (type == "телевізор") {
            std::cout << "Створено телевізор\n";
        }
        else {
            std::cout << "Такий тип електроніки не підтримується\n";
        }
    }
};

class Tshirt {};
class Pants {};
class Jacket {};

class Smartphone {};
class Laptop {};
class Television {};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ProductFactory* clothingFactory = new ClothingFactory();
    ProductFactory* electronicsFactory = new ElectronicsFactory();

    clothingFactory->createClothing("футболка");
    clothingFactory->createClothing("штани");
    clothingFactory->createClothing("куртка");

    electronicsFactory->createElectronics("смартфон");
    electronicsFactory->createElectronics("ноутбук");
    electronicsFactory->createElectronics("телевізор");

    delete clothingFactory;
    delete electronicsFactory;

    return 0;
}
