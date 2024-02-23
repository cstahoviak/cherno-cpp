#pragma once

#include <iostream>

struct Vec2
{
  float x, y;

  Vec2(float x, float y) : x(x), y(y) {};

  // If we don't use operator overloading, we would need to define a method that
  // allows us to add two Vec2s together. Reminder that marking the method as
  // "const" ensures that this method will not modify the member variables of
  // of the Struct.
  Vec2 add(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
  }

  // Use "operator overloading" to accomplish the same thing as above.
  Vec2 operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
  }

  // Use operator overloading to define scalar multiplication
  // TODO: Can I templatize this to extend to floats and doubles?
  Vec2 operator*(const int scalar) const {
    return Vec2(scalar * x, scalar * y);
  }

  // Use operator overloading to overload the == and != operators
  bool operator==(const Vec2 other) const {
    return x == other.y && y == other.y;
  }

  bool operator!=(const Vec2 other) const { return !(*this == other); }

};

// Cannot extend the << operator as a member-function of a class - it has to be
// a seperate function. The implementation of this function MUST be in
// types.cpp otherwise I'll get a "multiple definition of operator<<" error
// because the implementation gets included in multiple translation units.
std::ostream& operator<<(std::ostream& stream, const Vec2& vec);