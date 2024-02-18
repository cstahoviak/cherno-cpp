/*
 * Member Initializer Lists:
 * - 
 * - 
 */

#include <iostream>
#include <memory>

#include "entity.h"
#include "log.h"

int main() {
  // Member Initializer lists

  // Create an Entity via the default contructor
  std::cout << "1. Create Entity with Logger via the default constructor." 
    << std::endl;
  Entity e1 = Entity();

  // Create an Entity via the constructor that uses member initialization for
  // x and y, but not the the logger. Creating the Entity in this way will
  // create the Logger twice, but will throw away the first Logger instance that
  // is created - this is a waste of resoruces and time.
  std::cout << "\n2. Create Entity's Logger within the constructor." 
    << std::endl;
  Entity e2 = Entity(1, 10, Logger::LogLevel::WARNING);

  // Create an Entity via the constructor that uses member initialization for
  // x and y, but not the the logger. This is the most resource-conscious way to
  // create an Enitity with a Logger.
  std::cout << "\n3. Create Entity's Logger via member initialization."
    << std::endl;
  Entity e3 = Entity(Logger::LogLevel::WARNING);
  std::cout << std::endl;
  
}