#include <iostream>

struct Base {
    void f() {
        what();
    }
    virtual void what() {
        std::cout << "Base" << std::endl;
    }
};

struct Derived : Base {
    void what() {
        std::cout << "Derived" << std::endl;
    }
};

int main() {
    Base *x = new Derived();
    x->f();
}
