#include <iostream>

#include "default_constructor.h"

struct S {
  int n;

  explicit S(int); // constructor declaration

  S() : n(7) {} // constructor definition:
  // ": n(7)" is the initializer list
  // ": n(7) {}" is the function body
};

S::S(const int x) : n{x} {}
// constructor definition: ": n{x}" is the initializer list


int main() {
  S s;
  S s2(10);

  std::cout << "Hello, World!" << std::endl;
  return 0;
}