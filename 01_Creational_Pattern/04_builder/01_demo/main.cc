#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../../../lib/common.h"

class IBuilder {
public:
    virtual ~IBuilder() {}
    virtual void makeTitle(const std::string &title) = 0;
    virtual void makeString(const std::string &str) = 0;
    virtual void makeItems(const std::vector<std::string> &items) = 0;
    virtual void close() = 0;
};

class TextBuilder : public IBuilder {
public:
    void makeTitle(const std::string &title) override {
        m_str.append("============================\n");
        m_str.append("[" + title + "]\n");
        m_str.append("\n");
    }
    void makeString(const std::string &str) override {
        m_str.append(" * " + str + "\n");
        m_str.append("\n");
    }
    void makeItems(const std::vector<std::string> &items) override {
        for (auto item : items) {
            m_str.append(" .  " + item + "\n");
        }
        m_str.append("\n");
    }
    void close() override {
        m_str.append("============================\n");
    }
    std::string getResult() const {
        return m_str;
    }

private:
    std::string m_str;
};

class Director {
public:
    // Director(std::unique_ptr<IBuilder> &builder) : m_builder(std::move(builder)) {}  不要写引用
    Director(std::unique_ptr<IBuilder> builder) : m_builder(std::move(builder)) {}
    std::unique_ptr<TextBuilder> construct_text() {
        m_builder->makeTitle("Greeting");
        m_builder->makeString(u8"从早上到下午");
        m_builder->makeItems(std::vector<std::string>{ u8"早上好", u8"下午好" });
        m_builder->makeString(u8"晚上");
        m_builder->makeItems(std::vector<std::string>{ u8"晚上好", u8"晚安", u8"再见" });
        m_builder->close();
        // Downcast 
        auto tmp = static_cast<TextBuilder *>(m_builder.release());
        return std::unique_ptr<TextBuilder>(tmp);;
    }

private:
    std::unique_ptr<IBuilder> m_builder;
};

int main() {
    std::unique_ptr<IBuilder> builder = make_unique<TextBuilder>();
    Director director(std::move(builder));
    auto textbuilder = director.construct_text();
    std::string result = textbuilder->getResult();  
    std::cout << result << std::endl;

    return 0;
}