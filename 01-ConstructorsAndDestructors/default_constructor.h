//
// Created by Kexin Wei on 10/28/2024.
//
#pragma once

#ifndef DEFAULT_CONSTRUCTOR_H
#define DEFAULT_CONSTRUCTOR_H

struct A {
  int x;

  explicit A(const int x = 1): x(x) {} // user-defined default constructor
};

struct B : A {
  // B::B() is implicitly-defined, calls A::A()
};

struct C {
  A a;
  // C::C() is implicitly-defined, calls A::A()
};

struct D : A {
  explicit D(const int y) : A(y) {}

  // D::D() is not declared because another constructor exists
};

struct E : A {
  explicit E(const int y) : A(y) {}

  E() = default; // explicitly defaulted, calls A::A()
};

#endif //DEFAULT_CONSTRUCTOR_H
