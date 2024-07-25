/*
 * Video #105: Weak Pointers
 */
#include "entity.h"

#include <iostream>
#include <memory>

/**
 * @brief The StrongManager maintain a strong reference to the underlying Entity
 * object such that the StrongManager will ensure that the Entity does not go
 * out of scope before the StrongManager is finished with it.
 */
struct StrongManager
{
  std::shared_ptr<Entity> entity;
};

/**
 * @brief The WeakManager will NOT maintain a strong reference to the
 * underlying Entity object, i.e. the WeakManager will have no effect on the 
 * lifetime (scope) of the underlying Entity object.
 */
struct WeakManager
{
  std::weak_ptr<Entity> entity;

  /**
   * @brief As soon as we want to use or manipulate the underlying Entity
   * object, we want to have a strong reference to that object to prevent it
   * from going out of scope (e.g. a process on another thread could cause the
   * Entity to go out of scope and die) for the duration that we're
   * using/manipulating it.
   * 
   * We accomplish this via std::weak_ptr::lock() which returns a
   * std::shared_ptr to the underlying Entity.
   */
  void use_entity() {
    if (std::shared_ptr<Entity> e = entity.lock()) {
      // Do something with the Entity.
      std::cout << "Acquired lock on Entity at " << e.get() << std::endl;
    }
    else {
      std::cout << "Failed to aquire lock on Entity!" << std::endl;
    }
  }
};

// Forward declare B
struct B;

struct A {
    std::shared_ptr<B> ptr_b;
    ~A() { std::cout << "A destroyed!" << std::endl; }
};

/**
 * @brief If B chooses to maintain a strong reference to an instance of A via a
 * std::shared_ptr, then instances of both A and B will never go out of scope,
 * and will remain alive indefinitely (not good!).
 * 
 * Instead, if B maintains a weak reference to an instance of A via
 * std::weak_ptr, then we avoid this problem and instances of both A and B will
 * eventually be destroyed when they go out of scope.
 */
struct B {
    // std::shared_ptr<A> ptr_a;
    std::weak_ptr<A> ptr_a; 
    ~B() { std::cout << "B destroyed!" << std::endl; }
};

int main()
{
  {
    // Create a StrongManager
    StrongManager manager;
    std::cout << "Using the StrongManager:" << std::endl;

    {
      // Create an Entity via a shared pointer within a local scope.
      std::shared_ptr<Entity> e = std::make_shared<Entity>();

      // Assign the Entity to the manager
      manager.entity = e;
      
      // We expect the reference counter to be 2
      std::cout << "reference count at inner-most scope (expect 2): " <<
        manager.entity.use_count() << std::endl;
    }

    // At this point, e has not gone out of scope (died) since the StrongManager
    // maintains a reference to it. We expect the reference count to be 1.
    std::cout << "reference count at outer scope (expect 1): " <<
        manager.entity.use_count() << std::endl;
  }

  // At this point, the StrongManager has gone out of scope and the Entity has
  // died.


  {
    // Create a WeakManager
    WeakManager manager;
    std::cout << "\nUsing the WeakManager:" << std::endl;

    {
      // Create an Entity via a shared pointer within a local scope.
      std::shared_ptr<Entity> e = std::make_shared<Entity>();

      // Assign the Entity to the manager
      manager.entity = e;
      
      // We expect the reference counter to be 2
      std::cout << "reference count at inner-most scope (expect 2): " <<
        manager.entity.use_count() << std::endl;

      // Attempt to use the Entity via the WeakManager (expect to succeed)
      std::cout << "Attempting to use Entity at inner-most scope." << std::endl;
      manager.use_entity();
    }

    // At this point, e has gone out of scope and died because the WeakManager
    // will not ensure its survival beyond the scope it was created in
    std::cout << "reference count at outer scope (expect 0): " <<
        manager.entity.use_count() << std::endl;

    // Attempt to use the Entity via the WeakManager (expect to fail)
    std::cout << "Attempting to use Entity at outer scope." << std::endl;
    manager.use_entity();

    // We also expect the "expired" flag of the manager's weak pointer to be
    // true.
    std::cout << "WeakManager.entity.expired(): " << manager.entity.expired()
      << std::endl;
  }

  // An example of how shared pointers can keep cyclical references alive
  // indefinitely (not good!)
  {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->ptr_b = b;
    b->ptr_a = a;
  }
}