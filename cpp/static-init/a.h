#ifndef QWE
#define QWE

#include <iostream>

struct A {
    int qwe;
    static int a;
    static uint8_t i;
    static uint8_t init() {
        std::cout << "start init A" << std::endl;
        a = 1;
        std::cout << "end init A" << std::endl;
        return 100;
    }
};

struct B {
    static int a;
    static uint8_t i;
    static uint8_t init() {
        std::cout << "start init B" << std::endl;
        a = 2;
        A x;
        std::cout << x.qwe << std::endl;
        A::a = 2;
        std::cout << "end init B" << std::endl;
        return 100;
    }
};

#endif
