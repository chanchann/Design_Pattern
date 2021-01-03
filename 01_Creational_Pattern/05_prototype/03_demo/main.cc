#include <string>
#include <memory>
#include <iostream>
#include <unordered_map>
#include <cassert>
#include "../../../lib/common.h"

class IProduct {
public:
    virtual ~IProduct() = default;
    virtual std::unique_ptr<IProduct> Clone() = 0;    
    virtual void Use(const std::string &str) = 0;
};

class MessageBox : public IProduct {
public:
    MessageBox(const std::string &str) : m_name(str) {}
    std::unique_ptr<IProduct> Clone() override {
        return make_unique<MessageBox>(m_name);
    }
    void Use(const std::string &str) override {
        std::cout << "Message box " << m_name << " " << str << std::endl;
    }
private:
    std::string m_name;
};

class ProductMgr {
public:
    void Register(const std::string &name, std::unique_ptr<IProduct> pro) {
        // m_map.insert({ name, std::move(pro) });
        m_map[name] = std::move(pro);
    }
    std::unique_ptr<IProduct> Create(const std::string &name) {
        auto it = m_map.find(name);
        if (it != m_map.end()) {
            return it->second->Clone();
        } else {
            return nullptr;
        }
    }
private:
    std::unordered_map<std::string, std::unique_ptr<IProduct> > m_map;
};

int main() {
    ProductMgr mgr;
    std::unique_ptr<IProduct> p1 = make_unique<MessageBox>("Hello");
    p1->Use("World");
    std::cout << "p1 address : " << p1.get() << std::endl;
    mgr.Register("MB", std::move(p1));
    
    auto p2 = mgr.Create("MB");
    p2->Use("World");
    std::cout << "p2 address : " << p2.get() << std::endl;

    auto pp = mgr.Create("Not");
    assert(pp == nullptr);
    return 0;
}