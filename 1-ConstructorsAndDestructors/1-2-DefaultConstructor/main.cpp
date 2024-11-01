#include <iostream>

struct A {
  int x;
  void print() const { std::cout << x << std::endl; }
  explicit A(const int x = 1) : x(x) {}  // user-defined default constructor
};

struct B : A {
  // B::B() is implicitly-defined, calls A::A()
};

struct C {
  A a;
  // C::C() is implicitly-defined, calls A::A()
};

struct D : A {
  explicit D(const int y) : A(y) {}

  // D::D() is not declared because another constructor exists
};

struct E : A {
  explicit E(const int y) : A(y) {}

  E() = default;  // explicitly defaulted, calls A::A()
};

int main() {
  A a;  // Calls the default constructor
  B b;  // Calls the default constructor

  // D d; // illegally
  D d2(2);

  E e;
  E e2(3);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}