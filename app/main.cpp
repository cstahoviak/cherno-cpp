#include <iostream>
#include <memory>

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

  // SMART POINTERS
  // Create a shared pointer in thre scope of main
  std::shared_ptr<Entity> shared_entity = std::make_shared<Entity>();
  {
    // create a local scope and create a unique ptr within that scope. Once this
    // scope is exited, this pointer will be deleted.
    std::unique_ptr<Entity> entity_ptr = std::make_unique<Entity>();

    // create a shared ptr within the local scope and assign it to the
    // shared_entity ptr. Unlike the unique_ptr, the shared_entity ptr will not/
    // be deleted until after main exits.
    std::shared_ptr<Entity> e1 = shared_entity;
  }

  // CONST
  // Create a const pointer to an integer on the heap whereby the value pointed to cannot be modified
  const int* const_ptr = new int;
  // Can also write:
  // int const * const_ptr = new int;
  // The line below will error
  // *const_ptr = 100;
  // However, I can re-assign the const pointer
  const int MAX_SOMETHING = 100;
  const_ptr = &MAX_SOMETHING;

  // MUTABLE
  {
    int x = 100;
    // define a lambda that captures all local variables by value. Without the
    // "mutbale" keyword, all local variables captured by value would be
    // read-only. So why not capture by reference?
    auto f = [=]() mutable {
      x++;
      std::cout << "Inremented x to: " <<  x << std::endl;
    };
    f();

    // The value of x will remain UNCHANGED outside the lambda!
    std::cout << "x outside of lambda: " << x << std::endl;
  }

  std::cin.get();

  // Main doesn't actually require a return statement - main() is unique in this way
}