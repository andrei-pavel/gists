#include <iostream>


static int q = 1;
//void f(int a) {
//}

void f(int& a) {
}

void f(int&& a) {
    int b = 54;
    std::cout << &a << std::endl;
    std::cout << &b << std::endl;
    std::cout << &q << std::endl;
}

int main() {
    f(5);
    f(5);
    return 0;
}

