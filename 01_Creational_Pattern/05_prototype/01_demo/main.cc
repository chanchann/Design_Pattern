#include <iostream>
#include <string>
#include <unordered_map>
#include <memory>
#include "../../../lib/common.h"

using std::string;

enum class Type {
    PROTOTYPE_1 = 0,
    PROTOTYPE_2
};

class Prototype {
public:
    Prototype() = default;
    Prototype(string prototype_name)
        : _prototype_name(prototype_name) {
    }
    virtual ~Prototype() = default;
    virtual std::unique_ptr<Prototype> Clone() const = 0;
    virtual void Method(float prototype_field) {
        this->_prototype_field = prototype_field;
        std::cout << "Call Method from " << _prototype_name << " with field : " << prototype_field << std::endl;
    }
protected:
    string _prototype_name;
    float _prototype_field;
};

class ConcretePrototype1 : public Prototype {
public:
    ConcretePrototype1(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), _concrete_prototype_field1(concrete_prototype_field) {
    }

    std::unique_ptr<Prototype> Clone() const override {
        return make_unique<ConcretePrototype1>(*this);
    }
private:
    float _concrete_prototype_field1;
};

class ConcretePrototype2 : public Prototype {
public:
    ConcretePrototype2(string prototype_name, float concrete_prototype_field)
        : Prototype(prototype_name), _concrete_prototype_field2(concrete_prototype_field) {
    }
    std::unique_ptr<Prototype> Clone() const override {
        return make_unique<ConcretePrototype2>(*this);
    }
private:
    float _concrete_prototype_field2;
};

struct EnumClassHash {
    template <typename T>
    std::size_t operator()(T t) const {
        return static_cast<std::size_t>(t);
    }
};

class PrototypeFactory {
public:
    PrototypeFactory() {
        prototypes_[Type::PROTOTYPE_1] = make_unique<ConcretePrototype1>("PROTOTYPE_1 ", 50.f);
        prototypes_[Type::PROTOTYPE_2] = make_unique<ConcretePrototype2>("PROTOTYPE_2 ", 60.f);
    }
    ~PrototypeFactory() = default;

    std::unique_ptr<Prototype> CreatePrototype(Type type) {
        return prototypes_[type]->Clone();
    }
private:
    std::unordered_map<Type, std::unique_ptr<Prototype>, EnumClassHash> prototypes_;
};

void Client(PrototypeFactory& prototype_factory) {
    std::cout << "Let's create a Prototype 1\n";

    std::unique_ptr<Prototype> prototype1 = prototype_factory.CreatePrototype(Type::PROTOTYPE_1);
    prototype1->Method(90);


    std::cout << "\n";

    std::cout << "Let's create a Prototype 2 \n";
    std::unique_ptr<Prototype> prototype2 = prototype_factory.CreatePrototype(Type::PROTOTYPE_2);
    prototype2->Method(10);
}

int main() {
    PrototypeFactory prototype_factory;
    Client(prototype_factory);
    return 0;
}