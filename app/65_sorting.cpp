/*
 * Video #65: Sorting
 */

#include <algorithm>
#include <iostream>
#include <functional>
#include <vector>

template<typename T>
void print_values(std::vector<T>& values) {
  for (const auto& val : values) {
    std::cout << val << std::endl;
  }
  std::cout << "\n";
}

int main() {
  // Create a random vector of integers
  std::vector<int> values = {3, 5, 1, 4, 2};

  // Sort the vevtor using a built-in policy like std::greater
  std::sort(values.begin(), values.end(), std::greater<int>());
  print_values(values);

  // Sort values via a lambda
  std::sort(values.begin(), values.end(), 
    [](int a, int b){ return a < b; });
  print_values(values);

  std::cin.get();
  
}