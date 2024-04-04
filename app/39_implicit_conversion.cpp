/*
 * Video #39: Implicit Conversion and the 'explicit' keyword.
 */

#include "entity.h"

#include <iostream>

int main() {

// Use implicit conversion to contruct a Player from a string (pretty ugly to
//actually construct a Player object this way).
Player p1 = std::string("Carlito");
Player p2 = 32;

// Try to use the constructor marked as "explicit".
// NOTE: This doesn't error.. but why??
Player p3 = (std::string("Cherno"), 32);

std::cin.get();
}