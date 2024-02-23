/*
 * Video #37: How to Create/Instantiate Objects in C++ (Stack vs. Heap)
 */

#include <iostream>
#include <memory>

#include "entity.h"

int main() 
{
  // Create an object on the Stack
  Player p1("Default");

  // Create an Player pointer
  Player* p_ptr;

  // Create a local scope
  {
    // Create a player on the Heap with the 'new' keyword
    Player* player = new Player("Carlito");

    // Assign the player pointer (p_ptr) to the newly created Player on the Heap
    p_ptr = player;
    std::cout << p_ptr->get_name() << std::endl;
  }

  std::cin.get();

  // The player pointer was not declared in this scope - it cannot be deleted.
  // delete player;

  // Delete the Player on the Heap via the pointer outside the local scope above
  // that the "new" Player was assigned to.
  delete p_ptr;
}