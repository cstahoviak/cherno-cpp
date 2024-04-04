/*
* Video #85: l-values and r-values.
*/

#include <iostream>

// Overload of print_name that takes a const l-value reference. The "const" part
// makes this function compatible with both l-values and r-values.
void print_name(const std::string& name) {
  std::cout << "[l-value]: " << name << std::endl;
}

// Overload of print_name that takes an r-value reference. Even though the
// function above can also take an r-value, C++ will default to using this
// version of print_name when passed an r-value. This behavior will be useful
// when discussing move semantics!
void print_name(const std::string&& name) {
  std::cout << "[r-value]: " << name << std::endl;
}

int main () {
  std::string first = "Yan";
  std::string last = "Chernikov";
  std::string full = first + " " + last;

  // Call print_name with an l-value
  print_name(full);

  // Call print_name with an r-value;
  print_name(first + " " + last);

  std::cin.get();
}