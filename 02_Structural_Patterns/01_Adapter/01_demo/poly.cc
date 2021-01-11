/*
在 C++ 中， 可以使用多重继承来实现适配器模式。
*/

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

// 继承了函数拿来用
class Adapter : public Target, public Adaptee {
public:
    Adapter() {}
    std::string Request() const override {
        std::string to_reverse = SpecificRequest();
        std::reverse(to_reverse.begin(), to_reverse.end());
        return "Adapter: (TRANSLATED) " + to_reverse;
    }
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
    std::unique_ptr<Adapter> adapter = make_unique<Adapter>();
    ClientCode(std::move(adapter));
    std::cout << "\n";
    return 0;
}