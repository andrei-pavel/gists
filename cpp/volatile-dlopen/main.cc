#include <dlfcn.h>
#include <iostream>

// bool const done = true;
bool const volatile done = true;

void loop() {
    while(done) {
        std::cout << "in loop" << std::endl;
    }
}

int main() {
    void* handle = dlopen("./a.so", RTLD_LAZY);
    if (!handle) {
        std::cerr << "Error opening shared object" << std::endl;
        exit(1);
    }

    bool* local_done = dlsym(handle, "done");
    if (!local_done) {
        /* no such symbol */
        fprintf(stderr, "Error: %s\n", dlerror());
        dlclose(handle);
        return EXIT_FAILURE;
}

    loop();
    return 0;
}
