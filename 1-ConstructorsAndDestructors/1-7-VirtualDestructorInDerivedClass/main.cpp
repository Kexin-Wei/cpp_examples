#include <iostream>

// [When to Use Virtual Destructors in C++? - GeeksforGeeks](https://www.geeksforgeeks.org/when-to-use-virtual-destructors-in-cpp/)

using namespace std;

// Base class
class Base {
public:
  // Base class constructor
  Base() { cout << "base constructor" << endl; }

  // Base class destructor
  virtual ~Base() { cout << "base destructor" << endl; } // must virtual
};

// Derived class which is publicly inheriting the Base class
class Derived : public Base {
public:
  int* ptr;
  // Derived class constructor
  Derived() {
    ptr = new int[10];
    cout << "derived constructor" << endl;
  }

  // Derived class destructor
  ~Derived() {
    delete ptr;
    cout << "derived destructor" << endl;
  }
};

int main() {
  // Creating a new Derived object and assigning its
  // address to a Base class pointer
  Base* ptr = (Base*)new Derived();

  // Deleting the created object through the Base class
  // pointer. As the Base class destructor is not virtual,
  // it will not call the Derived class destructor. This
  // can lead to resource leak if the Derived class was
  // holding any resources
  delete ptr;

  return 0;
}