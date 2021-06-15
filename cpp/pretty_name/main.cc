#include <iostream>
#include <typeinfo>
#include <boost/core/demangle.hpp>

template <typename T>
std::string pretty_name() {
  return boost::core::demangle(typeid(T).name());
}

int main() {
    std::cout << typeid(int8_t).name() << std::endl;
    std::cout << typeid(char).name() << std::endl;
    std::cout << pretty_name<int8_t>() << std::endl;
    std::cout << pretty_name<char>() << std::endl;
}
