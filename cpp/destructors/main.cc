#include <iostream>

struct A {
  A() { std::cout << "A" << std::endl; }
  virtual ~A() { std::cout << "~A" << std::endl; }
};

struct B : A {
  B() { std::cout << "B" << std::endl; }
  ~B() { std::cout << "~B" << std::endl; }
};

struct C : B {
  C() { std::cout << "C" << std::endl; }
  ~C() { std::cout << "~C" << std::endl; }
};

int main() {
  A *a = new C();
  delete a;
  return 0;
}
