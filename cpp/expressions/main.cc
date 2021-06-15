#include <iostream>

int main() {
    int a = 0;
    int& c = a;
    c = 1;
    std::cout << a << std::endl;
}
