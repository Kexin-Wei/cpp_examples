#include <iostream>

struct S {
    int n;

    explicit S(int);  // 1.constructor declaration

    S() : n(7) {}  // 2.1constructor definition:
    // ": n(7)" is the initializer list
    // ": n(7) {}" is the function body
};

S::S(const int x) : n{x} {} // 2.2 constructor definition: ": n{x}" is the initializer list

// 3. delegating constructor
struct T {
    int x, y;

    T(const int x, const int y) : x(x), y(y) {};

    T() : T(1, 1) {}; // delegating constructor

};

int main() {
    S s1;
    S s2(10);

    T t1(2, 2);
    T t2;

    return 0;
}