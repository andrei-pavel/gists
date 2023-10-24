#include <iostream>
#include <vector>

template <typename t>
void f(t i, t j) {
    std::vector<int> v(i, j);
    for (int k : v) {
        std::cout << k << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<int> v{1, 2, 3, 4, 5};
    f(v.begin(), v.end());
    f(v.begin(), v.begin());
    f(v.begin() + 2, v.begin() + 2 + 2);
}
