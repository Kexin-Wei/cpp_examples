#include "Destructor.h"

#include <iostream>
TestDestructor::TestDestructor() {
  std::cout << "TestDestructor constructor" << std::endl;
}

TestDestructor::~TestDestructor() {
  std::cout << "TestDestructor destructor" << std::endl;
}

Container::Container() {
  std::cout << "Container constructor" << std::endl;
}

Container::~Container() {
  std::cout << "Container destructor" << std::endl;
}

void Container::setTestDestructor(TestDestructor& testDestructor) {
  m_testDestructor = testDestructor;
}