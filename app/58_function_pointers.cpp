/*
 * Video #58: Function Pointers
 */

// std::find_if() is part of the algorithm header
#include <algorithm>
#include <iostream>
#include <vector>

// Define a simple function that takes one argument
void simple_func(const int value) {
  std::cout << "Value: " << value << std::endl;
}

// Define a function that applies another function to each item in a vector
// Replace v'oid(*f)(int)' with 'std::function<void(int)>& f' to use modern C++
// syntax.
void for_each(const std::vector<int>& values, void(*f)(int)) {
  for (int value : values) {
    // Apply the function to each item in values
    f(value);
  }
}

int main() {
  // Create a function pointer called f 
void(*f)(int) = &simple_func;

// This is a great use case for auto since the function pointer type is ugly
auto f2 = &simple_func;

// Prefer using a typedef (alias) to the code above
typedef void(*Function)(int);
Function f3 = simple_func;

// Call the function via the function pointers
f(10);
f2(100);
f3(1000);

// Lets look at a slightly more interesting example that applies a function to
// a vector of items
std::vector<int> values = {1, 2, 3, 4, 5};
for_each(values, &simple_func);

// Use a 'lambda' as the function argument to for_each()
auto g = [](int value) { std::cout << "Value: " << value << std::endl; };
for_each(values, g);

// Another cool use of lambdas
int threshold = 3;
auto it = std::find_if(values.begin(), values.end(),
  [&threshold](int value) {return value > threshold; });
// Expect this to print '4' because 4 is the first value greater than 3.
int idx = it - values.begin();
std::cout << "values[" << idx << "] = " << *it 
  << " is greater than threshold=" << threshold << "." << std::endl; 

std::cin.get();
}