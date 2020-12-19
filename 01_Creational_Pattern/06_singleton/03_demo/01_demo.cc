/*
21天c++ P144

私有构造函数，私有赋值运算符，静态实例成员

知识点 : 
1. static
static 类的数据成员
static 函数中声明的局部变量
static 成员函数
*/

#include <iostream>
#include <string>

using namespace std;

class President {
private:
    President() {}; // private default constructor, prohibits creation from outside
    // 感觉下面直接delete掉就可，下一个试试这个example
    President(const President &); // private copy constructor, prohibits copy creation
    const President &operator=(const President &); // assignment operator, prohibits assignment

    string name;

public:
    // controlled instantiation
    static President &GetInstance() {
        // static objects are constructed only once
        static President onlyInstance;
        return onlyInstance;
    }

    string GetName() { return name; }

    void SetName(string InputName) { name = InputName; }
};

int main() {
    President &onlyPresident = President::GetInstance();
    onlyPresident.SetName("Abraham Lincoln");

    // uncomment lines to see how compile failures prohibit duplicates
    // President second; // cannot access constructor
    // President* third= new President(); // cannot access constructor
    // President fourth = onlyPresident; // cannot access copy constructor
    // onlyPresident = President::GetInstance(); // cannot access operator=

    cout << "The name of the President is: ";
    cout << President::GetInstance().GetName() << endl;

    return 0;
}