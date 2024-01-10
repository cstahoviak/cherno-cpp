#include <iostream>

#include "entity.h"
#include "log.h"

// Create a forward-declaration for the log function
// void log(const char*);

void increment_via_pointer(int* ptr)
{
  // Dereference the pointer before incrementing the value.
  (*ptr)++;
}

void increment_via_reference(int& val)
{
  // No need to deal with dereferencing pointers when passing by reference.
  val++;
}

int main()
{
  // FOR LOOPS
  for (int i = 0; i < 5; i++)
    {
      log("Howdy");
    }

  // POINTERS
  int a = 10;
  // void* ptr = &a;
  int* ptr = &a;
  // dereference pointer via the * operator and update value stored by a
  *ptr = 20;

  // REFERENCES
  int b = 100;
  std::cout << "b = " << b << std::endl;
  increment_via_pointer(&b);
  std::cout << "b = " << b << std::endl;
  increment_via_reference(b);
  std::cout << "b = " << b << std::endl;

  // CLASSES
  Logger logger;
  logger.set_level(Logger::INFO);
  logger.error("Howdy!");
  logger.warn("Howdy!");
  logger.info("Howdy!");

  // INHERITANCE
  Entity* entity = new Entity();
  show_name(entity);
  Player* player = new Player("Carl");
  show_name(player);

  // ARRAYS
  int arr[5];
  arr[0] = 2;
  arr[4] = 10;
  std::cout << arr[0] << std::endl;
  std::cout << arr << std::endl;

  std::cin.get();

  // Main doesn't actually require a return statement - main() is unique in this way
}