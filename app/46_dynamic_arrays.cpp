/*
 * Video #46: Dynamic Arrays in C++ (std::vector)
 */

#include "types.h"

#include <iostream>
#include <vector>

int main() {
  // Create a vector (list) of Vec2s
  std::vector<Vec2> vectors;

  // Add a vector to my list. This first push_back operation already invokes the
  // copy constructor once because a Vec2 instance is first instantiated in the
  // local stack frame of main() and then copied into the memory allocated by
  // 'vectors' vector. But what if we could constuct this first vector "in 
  // place" in the memory allocated by 'vectors'?
  std::cout << "Use push_back() to add elements:" << std::endl;
  vectors.push_back(Vec2(1, 2));

  // The copy constructor is invoked twice more by this next operation. Once for
  // the reason above, and a second time to copy the first vector into newly
  // resized vector that has allocated enough memory to store 2 Vec2 objects.
  vectors.push_back(Vec2(3, 4));

  // Iterate over the vector and print them via a "range-based" for loop
  for (const Vec2& vector : vectors) {
    std::cout << vector << std::endl;
  }

  // Remove the second element of vectors
  vectors.erase(vectors.begin() + 1);

  // Clear the list of vectors
  vectors.clear();

  // We can avoid the unecesary copy operations from above by using
  // std::vector.reserve() and std::vector.emplace_back().
  std::vector<Vec2> vectors2;
  vectors2.reserve(3);

  std::cout << "\nUse reserve() and emplace_back() to add elements:"
    << std::endl;
  vectors2.emplace_back(1,2);
  vectors2.emplace_back(3,4);
  vectors2.emplace_back(5,6);

  std::cin.get();
}