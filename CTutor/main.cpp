#include <iostream>
#include <string>


class Weapon {
public:
    virtual ~Weapon() {}
    virtual std::string Operation() const = 0;
};

class Sword : public Weapon {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteSword}";
    }
};
class Bow : public Weapon {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteBow}";
    }
};
class Dagger : public Weapon {
public:
    std::string Operation() const override {
        return "{Result of the ConcreteDagger}";
    }
};


class FabricWeapon {
    /**
     * Обратите внимание, что Создатель может также обеспечить реализацию
     * фабричного метода по умолчанию.
     */
public:
    virtual ~FabricWeapon() {};
    virtual Weapon* FactoryMethod() const = 0;

    std::string SomeOperation() const {
        // Вызываем фабричный метод, чтобы получить объект-продукт.
        Weapon* weapon = this->FactoryMethod();
        // Далее, работаем с этим продуктом.
        std::string result = "Creator: The same creator's code has just worked with " + weapon->Operation();
        delete weapon;
        return result;
    }
};


class ConcreteSword : public FabricWeapon {
public:
    Weapon* FactoryMethod() const override {
        return new Sword();
    }
};

class ConcreteBow : public FabricWeapon {
public:
    Weapon* FactoryMethod() const override {
        return new Bow();
    }
};

void ClientCode(const FabricWeapon& creator) {
    std::cout << "Client: I'm not aware of the creator's class, but it still works.\n"
        << creator.SomeOperation() << std::endl;
}


int main() {
    std::cout << "App: Launched with the Sword.\n";
    FabricWeapon* sword = new ConcreteSword();
    ClientCode(*sword);
    std::cout << std::endl;
    std::cout << "App: Launched with the Bow.\n";
    FabricWeapon* bow = new ConcreteBow();
    ClientCode(*bow);

    delete sword;
    delete bow;
    return 0;
}