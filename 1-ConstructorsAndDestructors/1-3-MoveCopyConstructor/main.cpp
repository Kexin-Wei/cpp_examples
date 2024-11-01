#include <iostream>

/*========================== Normal =============================*/

struct Normal {
  int a = 0;
  Normal(int a = 1) : a(a) {}
  Normal(const Normal& other) : a(other.a) {
    std::cout << "Copy constructor is called" << std::endl;
  }
  Normal(Normal&& other) : a(other.a) {
    std::cout << "Move constructor is called" << std::endl;
  }

  Normal& operator=(const Normal& other) {
    a = other.a;
    std::cout << "Copy assigment is called" << std::endl;
    return *this;
  }

  Normal& operator=(Normal&& other) {
    a = other.a;
    std::cout << "Move assigment is called" << std::endl;
    return *this;
  }
};

/*========================== Move ==============================*/

struct OnlyMove {
  int a;
  std::string s;

  // user defined constructor
  OnlyMove(int a = 1, std::string s = "test") : a(a), s(s) {}

  // copy constructor is deleted
  OnlyMove(const OnlyMove& other) = delete;

  // move constructor
  OnlyMove(OnlyMove&& other) : a(std::move(other.a)), s(std::move(other.s)) {
    other.a = 0;  // reset other object
    std::cout << "Move constructor is called" << std::endl;
  }

  //copy assigment is deleted
  OnlyMove& operator=(const OnlyMove& other) = delete;

  // move assigment
  OnlyMove& operator=(OnlyMove&& other) {
    a = std::move(other.a);
    s = std::move(other.s);
    other.a = 0;  // reset other object
    std::cout << "Move assigment is called" << std::endl;
    return *this;
  }

  void print() const { std::cout << "a = " << a << ", s = " << s << std::endl; }
};

/*========================== Main ==============================*/
int main() {

  // normal
  Normal a, b(2), c(b);
  a = b;

  // move only

  OnlyMove d(3), f(std::move(d)), g;       // move constructor is called
  std::cout << "d value is" << std::endl;  // d value is0
  d.print();

  d.a = 2;
  g = std::move(d);                         // move constructor is called
  std::cout << "d value is " << std::endl;  // d value is 0 2
  d.print();

  // OnlyMove h(d);  // error: use of deleted function 'OnlyMove::OnlyMove(const OnlyMove&)'
  // OnlyMove i = d;  // error: use of deleted function 'OnlyMove::OnlyMove(const OnlyMove&)'
  return 0;
}