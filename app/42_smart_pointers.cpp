/*
 * Video #42: Object Lifetime in C++ (Stack/Scope Lifetimes)
 * Video #43: Smart Pointers in C++
 * Video #45: The Arrow Operator in C++
 */

#include "entity.h"

#include <iostream>
#include <memory>

void observe(std::weak_ptr<Player> player) {
  if ( std::shared_ptr<Player> p = player.lock() ) {
    std::cout << "observe() able to lock weak_ptr<>, name: " << 
      p->get_name() << std::endl;
  }
  else {
    std::cout << "observe() able to lock weak_ptr<>. The underlying Player " <<
      "instance has expired." << std::endl;
  }
}


int main() {
  // Stack-allocate a "scoped" Entity pointer whose deletion will be managed
  // internally by the ScopedPtr class. This effectively makes the pointer
  // created with 'new' behave like a stack-allocated object.
  std::cout << "Scoped Entities:" << std::endl;
  {
    std::cout << "Entering local scope and creating ScopedPtr." << std::endl;
    
    // Create a const ScopedPtr (const objects can only call const member
    // methods of the class)
    const ScopedPtr e = new Entity(1.0, 10.0);
    
    // (Video #45) Because we've overloaded the -> operator, we can access the
    // public members of Entity via the Scoped Pointer.
    std::cout << "Entity(x=" << e->get_x() << ", y=" << e->get_y() << ")" 
      << std::endl;

    std::cout << "Exiting local scope." << std::endl;
  }

  // Create a shared pointer within the scope of main()
  std::cout << "\nShared Pointers:" << std::endl;
  std::shared_ptr<Player> shared_player = std::make_shared<Player>("Shared");
  {
    // Create a local scope and create a unique pointer within that scope. Once
    // this scope is exited, this pointer will be deleted.
    std::unique_ptr<Player> entity_ptr = std::make_unique<Player>("Unique");

    // Create a shared ptr within the local scope and assign it to the
    // shared_entity ptr. Unlike the unique_ptr, the shared_entity ptr will not
    // be deleted until after main exits.
    std::shared_ptr<Player> e1 = shared_player;
  }

  // Create a weak pointer to a Player
  std::weak_ptr<Player> weak_player;
  {
    // Create a shared pointer to a Player. This player will go out of scope
    // once the local scope is exited.
    std::shared_ptr<Player> player = std::make_shared<Player>("Shared");

    // Assign the weak pointer to the shared pointer.
    std::cout << "Assigning a weak_ptr to an existing shared_ptr." << std::endl;
    weak_player = player;
    // Use the Player instance via a weak_ptr
    observe(weak_player);
  }

  // At this point, the weak pointer should be expired.
  std::cout << "shared_ptr has gone out of scope, weak_ptr should be " <<
    "expired." << std::endl;
  std::string expired = weak_player.expired() ? "True" : "False";
  std::cout << "weak_player expired: " << expired << std::endl;
  observe(weak_player);

  // (9/10/24) Further experimentation with shared pointers.
  Player player{"Carl"};

  // Create a shared pointer to the player in the outer scope
  {
    std::shared_ptr<Player> shared_player = std::shared_ptr<Player>(&player);
    std::cout << "Access via shared_ptr: " << shared_player->get_name() <<
      std::endl;
  }

  // This line below will throw a "double free or corruption" segfault because
  // the Player was previously deleted when the shared_ptr went out of scope.
  // std::cout << "Access via instance: " << player.get_name() << std::endl;

  std::cin.get();
}