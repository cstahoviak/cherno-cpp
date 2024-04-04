/*
 * Video #93: Iterators
 */

#include <iostream>
#include <unordered_map>
#include <vector>

int main() {
  // Use a vector to demonstrate iteration
  std::vector<int> values = {1, 2, 3, 4, 5};

  // One type of for loop for container iteration
  std::cout << "Index-based iteration:" << std::endl;
  for (size_t idx = 0; idx < values.size(); idx++) {
    // grab the value via index
    std::cout << "value: " << values[idx] << std::endl;
  }

  // A "range-based" for loop (since C++11) is slightly cleaner
  std::cout << "\nRange-based iteration:" << std::endl;
  for (int& val : values) {
    std::cout << "value: " << val << std::endl;
  }

  // Use an iterator to traverse the container
  // Q: Is pre- or post-increment better for incrementing the iterator?
  std::cout << "\nIterator-based iteration:" << std::endl;
  for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
    // Dereference the iterator (bc it's a pointer) to get the value
    std::cout << "value: " << *it << std::endl;
  }

  // Let's look at a data structure, the "unordered map", that doesn't support
  // indexing and instead stores its values in no particular order via a
  // hash-map.
  std::unordered_map<std::string, int> map;
  map["Cherno"] = 0;
  map["C++"] = 5;

  // Let's iterate over our unordered map
  std::cout << "\nIterator-based iteration over an unordered map:" << std::endl;
  using SimpleMap = std::unordered_map<std::string, int>;
  for (SimpleMap::const_iterator it = map.begin(); it != map.end(); it++) {
    std::string key = it->first;
    int value = it->second;
    std::cout << key << ": " << value << std::endl;
  }

  // The unordered map container also supports range-based iteration
  std::cout << "\nRange-based iteration over an unordered map:" << std::endl;
  for (std::pair<std::string, int> kv : map) {
    // kv is short for "key-value"
    std::string key = kv.first;
    int value = kv.second;
    std::cout << key << ": " << value << std::endl;
  }

  // As of C++17, we're able to use "structured bindings" to clean things up
  // even further.
  std::cout << "\nC++17 range-based iteration over an unordered map:"
    << std::endl;
  for (auto [key, value] : map) {
    std::cout << key << ": " << value << std::endl;
  }
}