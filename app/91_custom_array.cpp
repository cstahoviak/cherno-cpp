/*
* Video #91: ARRAY - Making Data Structures in C++
*/
#include "array.h"

#include <array>
#include <cstring>
#include <iostream>

int main() {
  // Create a small integer (stack-allocated) array
  int arr[5];

  // Remember that a heap-allocated array would look something like
  int* heap_arr = new int[5];

  // Let's make use of std::array
  std::array<int, 10> collection;

  // I can easily get an array's size and iterate over it. We want to recreate
  // this functionality in the API of our custom array class.
  size_t size = collection.size();
  for (int& val : collection) {
    // do stuff
  }

  // Let's use our custom array class
  Array<int, 5> array;

  // Iterate over the uninitialized array
  std::cout << "Pre-initialization:" << std::endl; 
  for (size_t idx = 0; idx < array.size(); idx++) {
    std::cout << "[" << idx << "]: " << array[idx] << std::endl;
  }

  // Initialize the array and iterate over it again
  std::memset(&array[0], 0, array.size() * sizeof(array[0]));
  std::cout << "\nPost-initialization:" << std::endl; 
  for (size_t idx = 0; idx < array.size(); idx++) {
    std::cout << "[" << idx << "]: " << array[idx] << std::endl;
  }

  // Use our custom array class with strings
  std::cout << "\nString Array:" << std::endl;
  Array<std::string, 2> str_arr;
  str_arr[0] = "Cherno";
  str_arr[1] = "C++";
  // Cannot write a range-based for loop (yet!)
  // for (std::string& str : str_arr) {
  //   std::cout << str << std::endl;
  // }
  // Have to iterate via size() for now
  for (size_t idx = 0; idx < str_arr.size(); idx++) {
    std::cout << "[" << idx << "]: " << str_arr[idx] << std::endl;
  }
}