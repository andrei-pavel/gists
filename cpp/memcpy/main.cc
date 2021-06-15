#include <cstring>
#include <iostream>

void f() {
    char a[16];
    char b[16] = "123456789012345";
    memcpy(a, b, 8);
    memcpy(a + 8, b + 8, 8);
    std::cout << a << std::endl;
}

void g() {
    char a[16];
    char b[16] = "123456789012345";
    memcpy(&a, &b, 8);
    memcpy(&a + 8, &b + 8, 8);
    std::cout << a << std::endl;
}

int main() {
    f();
    g();
}
