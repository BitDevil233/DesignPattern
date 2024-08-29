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
