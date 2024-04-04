/*
 * Video #94: Writing an Iterator (for our custom Vector class)
 */

#include "vector.h"

int main() {
  // Create an instance of our custom vector
  Vector<int> values;

  // Populate the vector (since we don't currently support initializer lists)
  for (int i = 0; i < 5; i++) {
    values.emplace_back(i);
  }

  // Iterate via a range-based for loop
  std::cout << "Range-based iteration:" << std::endl;
  for (int& val : values)
    std::cout << "value: " << val << std::endl;

  // Iterate by using an iterator explicitly
  std::cout << "\nIterator-based iteration:" << std::endl;
  for (Vector<int>::Iterator it = values.begin(); it != values.end(); it++)
    std::cout << "value: " << *it << std::endl;
}
