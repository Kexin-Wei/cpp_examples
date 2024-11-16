// have to mention implicit conversion for explicit
// Numeric conversions
int x = 3.14;    // double implicitly converted to int, x becomes 3
double d = 42;   // int implicitly converted to double, d becomes 42.0

// Built-in promotions
char c = 'a';
int i = c;       // char implicitly converted to int

// User-defined conversions via constructors
class MyString {
public:
    MyString(const char *str) { /* ... */ }  // Allows implicit conversion
};

void foo(MyString s) { /* ... */ }

// Another common example with numbers
class Number {
public:
    Number(int x) { value = x; }  // Non-explicit constructor
private:
    int value;
};

void processNumber(Number n) { /* ... */ }

class NumberEp {
public:
    explicit NumberEp(int x) { value = x; }

private:
    int value;
};

void processNumber(NumberEp n) {}

int main() {
    foo("hello");  // const char* implicitly converted to MyString
    Number num = 42;        // Implicit conversion from int to Number
    processNumber(123);     // Implicit conversion in function call

    // NumberEp num2 = 42;        // Error: implicit conversion disabled
    NumberEp num3(42);         // OK: explicit construction
    auto num4 = NumberEp(42); // OK: explicit conversion
    processNumber(123);     // Error: implicit conversion disabled
    processNumber(NumberEp(123)); // OK: explicit conversion
    return 0;
}


