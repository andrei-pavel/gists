struct struct_t {
    int* f() {
        thread_local int i = 1;
        return &i;
    }

    int* g() {
        return f();
    }

    int* h() {
        return f();
    }
};
