#include <iostream>
#include <map>

// rule of zero
struct Named_map {
public:
    explicit Named_map(string n) : name(std::move(n)) {}
    // no copy/move constructors
    // no copy/move assignment operators
    // no destructor
private:
    string name;
    std::map<int, int> rep;
};

// rule of three ( an older version of rule of five before c++ 11 )


// rule of five ( c++11 )
// If you define or =delete any copy, move, or destructor function, define or =delete them all
class AbstractBase {
public:
    virtual void foo() = 0;  // at least one abstract method to make the class abstract
    virtual ~AbstractBase() = default;
    // ...
};

class CloneableBase {
public:
    virtual std::unique_ptr<CloneableBase> clone() const;

    virtual ~CloneableBase() = default;

    CloneableBase() = default;

    CloneableBase(const CloneableBase &) = delete;

    CloneableBase &operator=(const CloneableBase &) = delete;

    CloneableBase(CloneableBase &&) = delete;

    CloneableBase &operator=(CloneableBase &&) = delete;
    // ... other constructors and functions ...
};

std::unique_ptr<CloneableBase> CloneableBase::clone() const {
    return {}; // ! avoid repeated return type
}

int main() {

    std::cout << "Hello, World!" << std::endl;

    return 0;
}