[toc]

# 迭代器(Iterator)模式
## 迭代器(Iterator)模式中的角色

### 1. Iterator 迭代器

1. 作用：按顺序逐个遍历元素

### 2. ConcreteIterator 具体的迭代器

1. 作用：实现Iterator的具体接口

### 3. Aggregate 集合

1. 作用：创建Iterator角色

### 4. ConcreteAggregate角色

1. 作用：实现具体的创建Iterator

### 5. Object

1. 作用：被迭代器按顺序访问的元素

## 为什么要用迭代器模式
相比较直接在具体类中编写用于迭代的函数，引用迭代器模式后，可以将遍历和实现分开，在main函数中，while循环其实不依赖BookShelf中的迭代实现。即做到了，将遍历动作和遍历能力解耦。

## 为什么要用设计模式
用具体类、具体函数解决问题，很容易导致类之间的耦合。为了弱化类之间的耦合，使得了类更加容易被作为一个**组件**而复用，就需要引入抽象类


# 虚函数

### 1. C++有专门的接口类型吗

- C++中没有专门的接口类型，所以用抽象类模拟接口,而抽象类是一个包含至少一个纯虚函数的类。

### 2. 抽象类不需要用类似abstruct的关键字来标识吗

- 在C++中，抽象类不需要像其他一些编程语言（例如C#中的abstract）那样使用专门的关键字来标识。

### 3. 什么是纯虚函数

- 纯虚函数是一种没有实现的函数，必须在派生类中重写，否则派生类也将是抽象的。

### 4. 虚函数和纯虚函数的区别是什么

- 虚函数

  - 定义：在基类中声明为 virtual 的函数，被称为虚函数。
  - 作用：虚函数允许派生类重写它，从而实现动态多态性，即通过基类指针或引用调用函数时，实际调用的是派生类的重写版本。
- 纯虚函数

  - 定义：在基类中声明为 virtual 并且等于 0 的函数，被称为纯虚函数。纯虚函数没有函数体，只能在派生类中实现。
  - 作用：纯虚函数使得包含它的类成为抽象类，不能创建该类的实例，必须由派生类实现纯虚函数。

### 5. 虚析构函数如何确保派生类的析构函数被正确调用

- 当你通过基类指针或引用删除一个派生类对象时，如果基类的析构函数不是虚函数，那么只有基类的析构函数会被调用，而派生类的析构函数不会被调用。这会导致派生类中特定资源（如动态分配的内存、文件句柄等）无法正确释放。
- 如下面的例子：

```cpp
class Animal {
public:
    Animal(){
        std::cout << "Animal Construct" << std::endl;
    };
    // 这里，析构函数没有添加virtual关键字
    ~Animal()
    {
        std::cout << "Animal Destruct" << std::endl;
    };
    virtual void makeSound() const {
        std::cout << "动物的声音" << std::endl;
    }
};

class Dog : public Animal {
public:
    Dog(){
        std::cout << "Dog Construct" << std::endl;
    };
    ~Dog(){
        std::cout << "Dog Destruct" << std::endl;
    };
    void makeSound() const override {
        std::cout << "汪汪" << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(){
        std::cout << "Cat Construct" << std::endl;
    };
    ~Cat(){
        std::cout << "Cat Destruct" << std::endl;
    };
    void makeSound() const override {
        std::cout << "喵喵" << std::endl;
    }
};

void playSound(const Animal& animal) {
    animal.makeSound();
}

int main() {
    Dog dog;
    Cat cat;
    Animal* animal = new Cat();
    // 一般delete之后，先执行Cat的析构函数，再执行Animal的析构函数，但是不在Animal的析构函数中添加virtual关键字时，在打印终端中只能看到Animal的析构被调用，Cat的析构没有被调用。
    delete animal;
    playSound(dog);  // 输出 "汪汪"
    playSound(cat);  // 输出 "喵喵"
}
```

### 6. 如果基类函数没有添加virtual关键字，该函数可以被重写吗？

- 如果基类函数没有添加 virtual 关键字，该函数在派生类中仍然可以被重写，但这种重写不会具有多态性。也就是说，通过基类指针或引用调用该函数时，将不会调用派生类中的重写版本，而是调用基类中的版本。

### 7. `virtual ~Iterator_BC() = default;`这句代码是什么意思？

- 定义一个虚析构函数，确保基类指针删除派生类对象时，能够正确调用派生类的析构函数（见第5条）。
- 使用编译器生成的默认析构函数实现，以**减少手动编写代码的工作量**。

### 8. 声明函数时，参数列表后面的 `cons`关键字是什么意思？

- 在C++中，当函数声明中的参数列表后面跟着一个 const 关键字时，它表示该函数是一个“常量成员函数”。这意味着该函数承诺不会修改所属类的任何成员变量（除非这些成员变量被标记为 mutable）。这种约束对于确保对象的不可变性和线程安全性非常有用。常量成员函数可以被常量对象调用，而非常量成员函数则不能

# 多态

### 1. 什么是多态

多态（Polymorphism）是面向对象编程的一个核心概念，指的是同一操作在不同对象上的不同表现形式。它使得可以编写出具有更高扩展性和可维护性的代码。

### 2. 多态的类型

多态主要分为两种类型：

- **编译时多态（静态多态）**：
  - 函数重载
  - 运算符重载
- **运行时多态（动态多态）**：
  - 虚函数
  - 纯虚函数和抽象类

### 3. 编译时多态

**函数重载**：在同一作用域内可以有多个同名函数，只要它们的参数列表不同即可。

```cpp
class Print {
public:
    void display(int i) {
        std::cout << "整数: " << i << std::endl;
    }
  
    void display(double f) {
        std::cout << "浮点数: " << f << std::endl;
    }
  
    void display(std::string s) {
        std::cout << "字符串: " << s << std::endl;
    }
};
```

**运算符重载**：允许给标准运算符赋予用户定义的意义。

```cpp
class Complex {
public:
    int real, imag;
    Complex(int r, int i) : real(r), imag(i) {}
    Complex operator + (const Complex &c) {
        return Complex(real + c.real, imag + c.imag);
    }
};
```

### 4. 运行时多态

**虚函数**：在基类中使用 `virtual` 关键字声明的函数。在派生类中可以重写这个函数。通过基类指针或引用调用该函数时，会根据实际指向的对象类型调用对应的函数实现。

```cpp
class Base {
public:
    virtual void show() {
        std::cout << "Base 类的 show 函数" << std::endl;
    }
};

class Derived : public Base {
public:
    void show() override {
        std::cout << "Derived 类的 show 函数" << std::endl;
    }
};

int main() {
    Base* b = new Derived();
    b->show();  // 调用 Derived 类的 show 函数
    delete b;
}
```

**纯虚函数和抽象类**：纯虚函数是一种没有具体实现的虚函数，用来定义接口。包含纯虚函数的类称为抽象类，不能实例化对象。

```cpp
class AbstractBase {
public:
    virtual void pureVirtualFunction() = 0;  // 纯虚函数
};

class ConcreteDerived : public AbstractBase {
public:
    void pureVirtualFunction() override {
        std::cout << "ConcreteDerived 实现纯虚函数" << std::endl;
    }
};

int main() {
    AbstractBase* ab = new ConcreteDerived();
    ab->pureVirtualFunction();  // 调用 ConcreteDerived 实现的纯虚函数
    delete ab;
}
```

### 5. 虚表（Vtable）

虚函数的实现机制依赖于虚表（Vtable）。每个包含虚函数的类都有一个虚表，表中存储了该类的虚函数指针。在运行时，通过基类指针调用虚函数时，会通过虚表找到实际的函数地址并进行调用。

### 6. 多态的优势

- **代码重用**：通过多态，基类指针或引用可以指向不同的派生类对象，减少了代码的重复。
- **可扩展性**：增加新的派生类时，无需修改已有的代码，只需保证新类实现了基类的接口。
- **灵活性**：允许程序在运行时动态确定调用哪个函数，实现更灵活的设计。

# 智能指针
