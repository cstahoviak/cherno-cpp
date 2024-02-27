/*
 * Video #53: Templates
 */
#include <iostream>

#include "types.h"
#include "utils.h"

int main() {
  // Use a templated print function to print different types
  print(10);
  print("Cherno");
  print(1.0f);

  // Also valid to call print and specify the type explicity. Most of the time,/
  // the compiler can infer the type and this isn't necessary.
  print<double>(10.0);

  // Create an instance of our templated array clamakess;
  Array<int, 10> array;
  std::cout << "Array size: " << array.size() << std::endl;

  // Use the WAIT template (aliased to std::cin.get())
  WAIT;
}