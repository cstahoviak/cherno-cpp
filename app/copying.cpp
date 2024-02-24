/*
 * Video #44: Copying and Copy Constructors
 */
#include <iostream>

#include "types.h"

int main() {
  // Create a String
  String str = "Cherno";
  std::cout << "Original string: '" << str << "'" << std::endl;

  // Copy that string into another string
  String str2 = str;

  // Show that modifying the second string doesn't change the first
  str2[2] = 'a';
  std::cout << "Copied and Modifed string: '" << str2  << "'" << std::endl;

  std::cin.get();
}