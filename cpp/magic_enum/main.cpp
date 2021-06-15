#include <magic_enum.hpp>
#include <iostream>

enum e {
    b = 0,
    c = 5
};

int main() {
    e a(b);
    std::cout << magic_enum::enum_name(a) << std::endl;
    return 0;
}
