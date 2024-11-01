#include <iostream>

int a = 0;
int* returnInt(int* a) {
  if (*a >= 0) {
    return a;
  } else {
    return nullptr;
  }
}

int main() {
  int* b = new int(2);

  if (b = returnInt(&a)) {
    std::cout << "return not null" << std::endl;
  } else {
    std::cout << "return null" << std::endl;
  }

  if (b) {
    std::cout << "b is not nul, b = " << *b << std::endl;
  } else {
    std::cout << "b is null" << std::endl;
  }

  return 0;
}