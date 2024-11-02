#include <iostream>
// check this article: https://dzone.com/articles/code-smell-series-parallel-inheritance-hierchies
struct Var {
  double a;
  int b;
  Var(double a, int b) : a(a), b(b) {}
  Var() : Var(0.0, 0) {}
  void print() { std::cout << "a: " << a << ", b: " << b << std::endl; }
};

struct Var2 : public Var {
  double c;
  Var2(double a, int b, double c) : Var(a, b), c(c) {}
  Var2() : Var2(0.0, 0, 0.0) {}
  void print() {
    std::cout << "a: " << a << ", b: " << b << ", c: " << c << std::endl;
  }
};

class BaseClass {
 public:
  BaseClass() { std::cout << "BaseClass constructor" << std::endl; }
  virtual ~BaseClass() { std::cout << "BaseClass destructor" << std::endl; }
  virtual void print() {
    getVar()->print();
    std::cout << "BaseClass print" << std::endl;
  }

 protected:
  virtual Var* getVar() = 0;
};

class DerivedClass : public BaseClass {
 public:
  DerivedClass() { std::cout << "DerivedClass constructor" << std::endl; }
  ~DerivedClass() { std::cout << "DerivedClass destructor" << std::endl; }

  void print() override {
    getVar()->print();
    std::cout << "DerivedClass print" << std::endl;
  }

 private:
  Var2* getVar() override {
    auto a = new Var2(1.0, 2, 3.0);
    return a;
  }
};

int main() {

  DerivedClass derivedClass;
  derivedClass.print();
  return 0;
}