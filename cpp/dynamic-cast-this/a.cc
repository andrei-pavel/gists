#include <cassert>

struct A {
    virtual ~A() = default;
    void f();
};

struct B : A {
    virtual ~B() = default;
};

struct BB : B {
};

struct C : A {
    virtual ~C() = default;
};

struct CC : C {
};

void A::f() {
    assert(dynamic_cast<B*>(this));
};

int main() {
    BB bb;
    A *a = new BB();
    a->f();
}
