#include "with-virtual.h"

struct B : A {
    void m() {
        std::cout << "B" << std::endl;
    }
};

int main() {
    A* a = new B();
    a->m();
    delete a;
    return 0;
}
