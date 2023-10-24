#include <iostream>
#include <string>
#include <typeinfo>
#include <boost/core/demangle.hpp>

template <typename T>
std::string pretty_name() {
  return boost::core::demangle(typeid(T).name());
}

int main() {
    typedef std::string typedef_string;
    using using_string = std::string;
    std::cout << typeid(int8_t).name() << std::endl;
    std::cout << typeid(char).name() << std::endl;
    std::cout << pretty_name<int8_t>() << std::endl;
    std::cout << pretty_name<char>() << std::endl;

    std::cout << typeid(std::string).name() << std::endl;
    std::cout << typeid(typedef_string).name() << std::endl;
    std::cout << typeid(using_string).name() << std::endl;

    std::cout << pretty_name<std::string>() << std::endl;
    std::cout << pretty_name<typedef_string>() << std::endl;
    std::cout << pretty_name<using_string>() << std::endl;
}
