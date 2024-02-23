#include <iostream>

#include "types.h"

// Takes a ostream reference and returns an ostream reference. Passing and
// returning by value will cause errors.
std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
  return stream << "Vec2(x=" << vec.x << ", y=" << vec.y << ")";
}