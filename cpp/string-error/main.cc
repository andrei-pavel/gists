#include <string>

int main() {
    // terminate called after throwing an instance of 'std::logic_error'
    // what():  basic_string::_M_construct null not valid
    // std::string a(nullptr);
    // std::string a(nullptr, 100);

    // terminate called after throwing an instance of 'std::length_error'
    // what():  basic_string::_M_create
    // std::string a(-1, 'a');
}
