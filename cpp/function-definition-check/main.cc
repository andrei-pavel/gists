#include <iostream>

using namespace std;

int foo() {
    return 0;
}

int (*defined)() = foo;

int (*undefined)() = 0;

int main() {
    cout << "defined is ";
    if (defined) {
        cout << "defined" << endl;
    } else {
        cout << "undefined" << endl;
    }
    cout << "undefined is ";
    if (undefined) {
        cout << "defined" << endl;
    } else {
        cout << "undefined" << endl;
    }

    defined();

    return 0;
}
