#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <algorithm>
/*
区分局部静态和静态成员
*/
class Singleton {
protected:
    Singleton(const std::string value): value_(value) {}
    static Singleton* singleton_;
    std::string value_;

public:
    Singleton(Singleton &other) = delete;
    void operator=(const Singleton &) = delete;

    static Singleton& GetInstance(const std::string& value);

    std::string value() const{
        return value_;
    } 
};

Singleton& Singleton::GetInstance(const std::string& value) {
    static Singleton onlyInstance(value);
    return onlyInstance;
}

void ThreadFoo(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton& singleton = Singleton::GetInstance("FOO");
    std::cout << singleton.value() << "\n";
}

void ThreadBar(){
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    Singleton& singleton = Singleton::GetInstance("BAR");
    std::cout << singleton.value() << "\n";
}

void test01() {
    std::cout <<"If you see the same value, then singleton was reused (yay!\n" <<
            "If you see different values, then 2 singletons were created (booo!!)\n\n" <<
            "RESULT:\n";   
    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();
}

void Thread_Test(int i) {
    Singleton& singleton = Singleton::GetInstance(std::to_string(i));
    std::cout << singleton.value() << "\n";
}

void test02() {
    std::vector<std::thread> threads;
    for(unsigned i=0; i < 100000; ++i) {
        threads.push_back(std::thread(Thread_Test, i)); // 产生线程
    } 
    std::for_each(threads.begin(),threads.end(),
                    std::mem_fn(&std::thread::join)); // 对每个线程调用join()
}

int main() {
    test01();
    // test02();

    return 0;
}