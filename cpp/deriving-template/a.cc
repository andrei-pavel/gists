#include <iostream>

struct Base {
    virtual void f() = 0;
};

template <typename T>
struct Template {
};

struct Derived : Template<Base> {
    void f() {
        std::cout << "iată " << std::endl;
    }
};

int main() {
    Derived d;
    d.f();
}
