#include <iostream>
///类的单例模式
///用来在当前进程中创建一个实例




class Singleton {
public:
    static Singleton& get_instance() {///c++函数的静态变量具有唯一性，可以确保该类实例是唯一的，并且该函数外部也能使用
        static Singleton s;
        return s;
    }
    void show() {
        std::cout << "This is Singleton" << std::endl;
    }

private:
    Singleton() {}///构造函数私有化，就不能从外部创建该类实例
    Singleton(const Singleton&) = delete;//拷贝
    Singleton(const Singleton&&) = delete;//移动构造
    Singleton& operator=(const Singleton&) = delete;//赋值
};