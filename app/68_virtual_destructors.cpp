/*
 * Video #68: Virtual Destructors.
 */

#include <iostream>

class Base {
  public:
    Base() { std::cout << "Base Constructed." << std::endl; }
    ~Base() { std::cout << "Base Destroyed." << std::endl; }
};

class VirtualBase {
  // Marking the Destructor as 'virtual' forces an instance of a derived class
  // to call the base class's destructor.
  public:
    VirtualBase() { std::cout << "VirtualBase Constructed." << std::endl; }
    virtual ~VirtualBase() { 
      std::cout << "VirtualBase Destroyed." << std::endl;
    }
};

class Derived : public Base {
  public:
    Derived() { std::cout << "Derived Constructed." << std::endl; }
    ~Derived() { std::cout << "Derived Destroyed." << std::endl; }
};

class Derived2 : public VirtualBase {
  public:
    Derived2() { std::cout << "Derived2 Constructed." << std::endl; }
    ~Derived2() { std::cout << "Derived2 Destroyed." << std::endl; }
};

int main() {
  // Let's take a look at difference in order of operations when constructing
  // and destroying a base and derived class. We'll construct these on the heap
  // to be explicit and creation and deletion. What we'll notice for the derived
  // class is that the Base constructor is called first, followed by the Derived
  // constructor. When the Derived instance is destroyed, the reverse order
  // occurs.
  Base* base = new Base();
  delete base;
  std::cout << "\n";
  Derived* derived = new Derived();
  delete derived;

  // If we chose to treat an instance of the Derived class as if it were a Base
  // instance, you'll notice that the Derived destructor never gets called.
  std::cout << "\nNotice how the Derived destructor is not called:" <<
    std::endl;
  Base* poly = new Derived();
  delete poly;

  // We can force an instance of the derived class to call the destructor of the
  // base class when it's destroyed by marking the base class's destructor as
  // virtual
  std::cout << "\nIn this case, the VirtualBase destructor is called:" << 
    std::endl;
  VirtualBase* poly2 = new Derived2();
  delete poly2;

  std::cin.get();
}