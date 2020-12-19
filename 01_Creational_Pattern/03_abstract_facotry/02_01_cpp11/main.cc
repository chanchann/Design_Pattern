#include <iostream>
#include <string>

class AbstractProductA {
public:
    virtual ~AbstractProductA() {};
    virtual std::string UsefulFunctionA() const = 0;
};

class ConcreteProductA1 : public AbstractProductA {
public:
    std::string UsefulFunctionA() const override {
        return "The result of the product A1.";
    }
};

class ConcreteProductA2 : public AbstractProductA {
    std::string UsefulFunctionA() const override {
        return "The result of the product A2.";
    }
};

class AbstractProductB {
public:
    virtual ~AbstractProductB(){};
    virtual std::string UsefulFunctionB() const = 0;
    virtual std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const = 0;
};

class ConcreteProductB1 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B1.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B1 collaborating with ( " + result + " )";
    }
};

class ConcreteProductB2 : public AbstractProductB {
public:
    std::string UsefulFunctionB() const override {
        return "The result of the product B2.";
    }
    std::string AnotherUsefulFunctionB(const AbstractProductA &collaborator) const override {
        const std::string result = collaborator.UsefulFunctionA();
        return "The result of the B2 collaborating with ( " + result + " )";
    }
};

class AbstractFactory {
public:
    virtual AbstractProductA *CreateProductA() const = 0;
    virtual AbstractProductB *CreateProductB() const = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA1();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB1();
    }
};

class ConcreteFactory2 : public AbstractFactory {
public:
    AbstractProductA *CreateProductA() const override {
        return new ConcreteProductA2();
    }
    AbstractProductB *CreateProductB() const override {
        return new ConcreteProductB2();
    }
};

void ClientCode(const AbstractFactory &factory) {
    const AbstractProductA *product_a = factory.CreateProductA();
    const AbstractProductB *product_b = factory.CreateProductB();
    std::cout << product_b->UsefulFunctionB() << "\n";
    std::cout << product_b->AnotherUsefulFunctionB(*product_a) << "\n";
    delete product_a;
    delete product_b;
}

int main() {
    std::cout << "Client: Testing client code with the first factory type:\n";
    ConcreteFactory1 *f1 = new ConcreteFactory1();
    ClientCode(*f1);
    delete f1;
    std::cout << std::endl;
    std::cout << "Client: Testing the same client code with the second factory type:\n";
    ConcreteFactory2 *f2 = new ConcreteFactory2();
    ClientCode(*f2);
    delete f2;
    return 0;
}