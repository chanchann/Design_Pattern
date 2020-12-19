/*
21天c++ P144
*/

#include <iostream>
#include <string>

using namespace std;

class President {
private:
    President() = default; // private default constructor, prohibits creation from outside
    string name;

public:
    President(const President &) = delete; // private copy constructor, prohibits copy creation
    const President &operator=(const President &) = delete; // assignment operator, prohibits assignment

    // c++11标准做法.
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