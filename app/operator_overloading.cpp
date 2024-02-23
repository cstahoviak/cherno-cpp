/*
 * Video #40: Operators and Operator Overloading
 */

#include "types.h"

int main() {
  Vec2 a(1.0f, 10.0f);
  Vec2 b(2.0f, 20.0f);

  // Add two vectors via the "add" method and use the overloaded << operator 
  // (stream insertion) to print the result.
  Vec2 c = a.add(b);
  std::cout << "a + b = " << c << std::endl;

  // Add two vectors via the overloaded + operator.
  std::cout << "a + b = " << a + b << std::endl;
}