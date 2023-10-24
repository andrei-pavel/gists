#include <iostream>

int64_t a;

void set(uint32_t n) {
    a = n;
}

uint32_t get() {
    return a;
}

void f() {
    std::cout << "a: " << a << std::endl;
    std::cout << "get(): " << get() << std::endl;
    std::cout << "0 < a: " << ((0 < a) ? "true" : "false") << std::endl;
}

int main() {
    a = -1;
    f();
    set(-1);
    f();
}
