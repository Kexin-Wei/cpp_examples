#pragma once

class TestDestructor {
 public:
  TestDestructor();
  ~TestDestructor();
  //   TestDestructor(const TestDestructor& other) = delete;  // copy constructor is deleted
  //   TestDestructor& operator=(const TestDestructor& other) = delete;  // copy assignment operator is deleted
  int m_value = 0;
};

class Container {
 public:
  Container();
  ~Container();
  void setTestDestructor(TestDestructor& testDestructor);
  TestDestructor m_testDestructor;
};