#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "../../../lib/common.h"

class Target {
public:
    virtual ~Target() = default;

    virtual std::string Request() const {
        return "Target: The default target's behavior.";
    }
};

class Adaptee {
public:
    std::string SpecificRequest() const {
        return ".eetpadA eht fo roivaheb laicepS";
    }
};

class Adapter : public Target {
public:
    Adapter(std::unique_ptr<Adaptee> adaptee) : m_adaptee(std::move(adaptee)) {}
    std::string Request() const override {
        std::string to_reverse = m_adaptee->SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
private:
    std::unique_ptr<Adaptee> m_adaptee;
};


void ClientCode(const std::unique_ptr<Target> target) {
    std::cout << target->Request();
}

int main() {
    std::cout << "Client: I can work just fine with the Target objects:\n";
    std::unique_ptr<Target> target = make_unique<Target>();

    ClientCode(std::move(target));
    std::cout << "\n\n";
    std::unique_ptr<Adaptee> adaptee = make_unique<Adaptee>(); 
    std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
    std::cout << "Adaptee: " << adaptee->SpecificRequest();
    std::cout << "\n\n";

    std::cout << "Client: But I can work with it via the Adapter:\n";
    std::unique_ptr<Adapter> adapter = make_unique<Adapter>(std::move(adaptee));
    ClientCode(std::move(adapter));
    std::cout << "\n";
    return 0;
}