#include <iostream>
#include <map>
#include "Destructor.h"

int main() {

  std::map<int, TestDestructor*> mapWithPointer;
  std::map<int, TestDestructor> mapWithReference;

  for (auto i = 3; i > 0; i--) {
    mapWithPointer[i] = new TestDestructor();
    mapWithReference[i] = TestDestructor();
  }

  // remove with new TestDestructor()
  for (auto i = 3; i > 0; i--) {
    delete mapWithPointer[i];
  }
  return 0;
}