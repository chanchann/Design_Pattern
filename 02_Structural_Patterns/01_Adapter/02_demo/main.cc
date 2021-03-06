#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include "../../../lib/common.h"

class Painter {
public:
    virtual ~Painter() {}
    virtual void printStrong() = 0;
    virtual void printWeak() = 0;
};

class Banner {
public:
    Banner(const std::string &str) : m_str(str) {}
    void showWithParen() {
        std::cout << "(" << m_str << ")" << std::endl;
    }
    void showWithAster() {
        std::cout << "*" << m_str << "*" << std::endl;
    }

private:
    std::string m_str;
};

class PainterBanner : public Painter {
public:
    PainterBanner(const std::string &str) : 
            m_banner(make_unique<Banner>(str)) 
        {}
    void printStrong() override {
        m_banner->showWithParen();
    }
    void printWeak() override {
        m_banner->showWithAster();
    }
private:
    std::unique_ptr<Banner> m_banner;
};

int main(int argc, char **argv) {
    std::unique_ptr<Painter> painter = make_unique<PainterBanner>("HelloWorld");
    painter->printStrong();
    painter->printWeak();
    return 0;
}