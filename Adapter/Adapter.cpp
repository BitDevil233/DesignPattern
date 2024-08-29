#include <iostream>
#include <string>

// Banner 类
class Banner {
private:
    std::string str;
public:
    Banner(const std::string& string) : str(string) {}
    
    void showWithParen() {
        std::cout << "(" << str << ")" << std::endl;
    }
    
    void showWithAster() {
        std::cout << "*" << str << "*" << std::endl;
    }
};

// Print 接口
class Print {
public:
    virtual void printWeak() = 0;
    virtual void printStrong() = 0;
    virtual ~Print() {}
};

// PrintBanner 类
class PrintBanner : public Banner, public Print {
public:
    PrintBanner(const std::string& string) : Banner(string) {}
    
    void printWeak() override {
        showWithParen();
    }
    
    void printStrong() override {
        showWithAster();
    }
};

// Main 函数
int main() {
    Print* p = new PrintBanner("Hello");
    p->printWeak();
    p->printStrong();
    delete p;
    return 0;
}

/**
 * 代码实现了一个经典的适配器模式（Adapter Pattern）。在这种设计模式中，一个类通过包装另一个类来改变或增强其接口，以使其适应客户端的需求
 * 适配器模式：PrintBanner 类是适配器，它将 Banner 的接口适配成 Print 接口，使得客户端可以通过 Print 接口来使用 Banner 的功能。
 * 多态性：通过继承和实现接口，PrintBanner 类可以被视为 Print 类型，这种多态性使得代码更加灵活和可扩展。
 * 资源管理：在 C++ 中，动态分配的内存需要手动管理，代码中通过 delete 释放了内存。
 */