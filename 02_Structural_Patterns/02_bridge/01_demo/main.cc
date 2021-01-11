#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "../../../lib/common.h"

class Implementation {
public:
    virtual ~Implementation() {}
    virtual std::string OperationImplementation() const = 0;
};

class ConcreteImplementationA : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationA: Here's the result on the platform A.\n";
    }
};
class ConcreteImplementationB : public Implementation {
public:
    std::string OperationImplementation() const override {
        return "ConcreteImplementationB: Here's the result on the platform B.\n";
    }
};

class Abstraction {
protected:
    std::unique_ptr<Implementation> _implementation;

public:
    Abstraction(std::unique_ptr<Implementation> implementation) : 
                _implementation(std::move(implementation)) {
    }

    virtual ~Abstraction() = default;

    virtual std::string Operation() const {
        return "Abstraction: Base operation with:\n" +
            this->_implementation->OperationImplementation();
    }
};

class ExtendedAbstraction : public Abstraction {
public:

    ExtendedAbstraction(std::unique_ptr<Implementation> implementation) :
        Abstraction(std::move(implementation)) 
        {}

    std::string Operation() const override {
        return "ExtendedAbstraction: Extended operation with:\n" +
            this->_implementation->OperationImplementation();
    }
};

void ClientCode(const Abstraction& abstraction) {
    std::cout << abstraction.Operation();
}


int main() {
    Abstraction abstract(make_unique<ConcreteImplementationA>());
    ClientCode(abstract);
    std::cout << std::endl;

    ExtendedAbstraction ext(make_unique<ConcreteImplementationB>());
    ClientCode(ext);
    return 0;
}