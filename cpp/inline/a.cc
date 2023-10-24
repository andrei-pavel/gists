#include "a.h"
#include <iostream>

int main() {
    struct_t a;
    std::cout << a.g() << std::endl;
    std::cout << a.h() << std::endl;

    struct_t b;
    std::cout << b.g() << std::endl;
    std::cout << b.h() << std::endl;
}
