#include <iostream>
#include <memory>

struct C {
    C() {
        std::cout << "Constructor" << std::endl;
    }
    ~C() {
        std::cout << "Destructor" << std::endl;
    }
};

int main() {
    std::shared_ptr<C> p(new C(), [](C* c) { delete c; });
}

