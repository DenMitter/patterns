#include <iostream>
#include <string>
#include <vector>
#include <Windows.h>

class ObjectBuilder {
public:
    virtual ~ObjectBuilder() {}
    virtual void addComponent(std::string type, std::string parameters) = 0;
    virtual void printObject() = 0;
};

class Component1 : public ObjectBuilder {
public:
    Component1(std::string parameters) : parameters_(parameters) {}

    void addComponent(std::string type, std::string parameters) override {
        std::cout << "Компонент1 не має додаткових компонентів\n";
    }

    void printObject() override {
        std::cout << "Компонент1 з параметрами: " << parameters_ << std::endl;
    }

private:
    std::string parameters_;
};

class Component2 : public ObjectBuilder {
public:
    Component2(std::string parameters) : parameters_(parameters) {}

    void addComponent(std::string type, std::string parameters) override {
        std::cout << "Компонент2 не має додаткових компонентів\n";
    }

    void printObject() override {
        std::cout << "Компонент2 з параметрами: " << parameters_ << std::endl;
    }

private:
    std::string parameters_;
};

class Component3 : public ObjectBuilder {
public:
    Component3(std::string parameters) : parameters_(parameters) {}

    void addComponent(std::string type, std::string parameters) override {
        std::cout << "Компонент3 не має додаткових компонентів\n";
    }

    void printObject() override {
        std::cout << "Компонент3 з параметрами: " << parameters_ << std::endl;
    }

private:
    std::string parameters_;
};

class ObjectDirector {
public:
    ObjectDirector(ObjectBuilder* builder) : builder_(builder) {}

    void constructObject() {
        builder_->addComponent("Компонент1", "Параметри для компонента 1");
        builder_->addComponent("Компонент2", "Параметри для компонента 2");
        builder_->addComponent("Компонент3", "Параметри для компонента 3");
    }

private:
    ObjectBuilder* builder_;
};

class ConcreteObjectBuilder : public ObjectBuilder {
public:
    void addComponent(std::string type, std::string parameters) override {
        if (type == "Компонент1") {
            components_.push_back(new Component1(parameters));
        }
        else if (type == "Компонент2") {
            components_.push_back(new Component2(parameters));
        }
        else if (type == "Компонент3") {
            components_.push_back(new Component3(parameters));
        }
        else {
            std::cout << "Не вдалося додати компонент: невідомий тип\n";
        }
    }

    void printObject() override {
        std::cout << "Об'єкт містить компоненти:\n";
        for (auto* component : components_) {
            component->printObject();
        }
    }

    ~ConcreteObjectBuilder() {
        for (auto* component : components_) {
            delete component;
        }
    }

private:
    std::vector<ObjectBuilder*> components_;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ObjectBuilder* builder = new ConcreteObjectBuilder();
    ObjectDirector director(builder);

    director.constructObject();
    builder->printObject();

    delete builder;

    return 0;
}
