#include <cstring>
#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<int> v;
    std::cout << sizeof(v) << std::endl;
    for (int i = 0; i < 42; ++i) {
        v.push_back(1);
        std::cout << sizeof(v) << std::endl;
    }

    for (int i : v) {
        std::cout << i << std::endl;
    }

    std::memset(v, 0, sizeof(v));

    for (int i : v) {
        std::cout << i << std::endl;
    }
    return 0;
}
