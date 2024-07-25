#include <iostream>
#include <sstream>
#include <string>

#include "types.h"

// Takes a ostream reference and returns an ostream reference. Passing and
// returning by value will cause errors.
std::ostream& operator<<(std::ostream& stream, const Vec2& vec) {
  return stream << "Vec2(x=" << vec.x << ", y=" << vec.y << ")";
}

std::ostream& operator<<(std::ostream& stream, const Vec3& vec) {
  // TODO: Figure out a way to only print the last 4 of the address if in
  // Debug mode.
  std::stringstream ss;
  ss << &vec;
  return stream << "Vec3(x=" << vec.x << ", y=" << vec.y << ", z=" << 
    vec.z << ") (0x" << ss.str().substr(ss.str().size() - 4, 4) << ")";
}

std::ostream& operator<<(std::ostream& stream, const String& string) {
  if (string.buffer_) {
    return stream << string.buffer_;
  }

  return stream << "NULL";
}