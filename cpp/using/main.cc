#include <iostream>

struct A {
    void what() {
        std::cout << "A" << std::endl;
    }
};

struct B {
    void what() {
        std::cout << "B" << std::endl;
    }
};

template<int N>
struct adapter {};

template<>
struct adapter<1> {
    using type = A;
};

template<>
struct adapter<2> {
    using type = B;
};

template<int N>
using T = typename adapter<N>::type;

int main() {
    adapter<1>::type a; a.what();
    adapter<2>::type b; b.what();
    return 0;
}
