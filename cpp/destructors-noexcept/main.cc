struct A {
    ~A() noexcept(false) {
        throw(1);
    }
};

int main() {
    try {
        A a;
    } catch(...) {
    }
    return 0;
}
