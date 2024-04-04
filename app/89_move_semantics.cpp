/*
* Video #89: Move Semantics
* Video #90: std::move and the Move Assignment Operator
*/

#include "entity.h"
#include "types.h"

#include <iostream>

// class String
// {
//   // A simple string class (not exactly the ~best~ implementation of a string
//   // class). Note that this String class does not include or account for a 
//   // null-termination character.
//   public:
//     String() = default;
//     String(const char* string) {
//       m_size = std::strlen(string);
//       m_data = new char[m_size];
//       std::memcpy(m_data, string, m_size);

//       std::cout << "String Created!" << std::endl;
//     }

//     // Define a copy constructor that will allow a String to be copied.
//     String(const String& other) {
//       m_size = other.m_size;
//       m_data = new char[m_size];
//       std::memcpy(m_data, other.m_data, m_size);

//       std::cout << "String Copied!" << std::endl;
//     }

//     ~String() {delete[] m_data; }
  
//   private:
//     char* m_data;
//     uint32_t m_size;
// };

class Player2 : Entity
{
  // Define a new player class that stores its name using our custon String.
  // TODO: Update entity::Player to support construction from a String.
  public:
    Player2(const String& name) : name_(name) {}

    // Define a constructor that takes an r-value reference (a temporary object)
    // We need to use std::move here when taking in the name as a String, such
    // that the String move constructor is called instead of the String copy
    // constructor.
    Player2(String&& name) : name_(std::move(name)) {}

  private:
    String name_;
};

int main() {
  // Create a Player using our String class. This will invoke the String copy
  // constructor if we do not have a "move constructor" defined for the String
  // class.
  std::cout << "1) The Move Constructor:" << std::endl;
  Player2 p = Player2(String("Cherno"));

  // Note that we will get one call to the String destructor when the "hollow"
  // String object being "moved from" is destroyed. And then a second call to
  // the String destructor when actual heap-allocated String owned by the
  // Player2 is destroyed.

  std::cout << "\n2) The Move Assignment Operator:" << std::endl;

  // Now let's look at the "move assignment operator".
  String source = "Hello";
  String source2 = "World";

  // This will invoke the copy constructor (we don't want to do this)
  std::cout << "\n2a) Copying a String:" << std::endl;
  String dest1 = source;

  // Moving an existing object into a newly created object will invoke the "move
  // constructor operator". In this case, 'source' is an x-value (eXpiring
  // l-value) that we're casting to an r-value using std::move, and 'dest2' is
  // an l-value.
  std::cout << "\n2b) Moving a String via the Move Constructor:" << std::endl;
  std::cout << "\(pre-move) source: " << source << std::endl;
  String dest2 = std::move(source);
  std::cout << "\(post-move) source:  " << source << std::endl;

  // Note that writing the following is equivalent to std::move(source)
  // String dest2 = (String&&)source;
  // String dest2((String&&)source);

  // If we want to invoke the "move assignment operator", we need to "move" an
  // existing l-value into another existing l-value.
  std::cout << "\n2c) Moving a String via Move Assignment:" << std::endl;
  String dest3;
  std::cout << "(pre-move) source2: " << source2 << ",\t dest3: " << 
    dest3 << std::endl;
  // The two lines below are equivalent - both call the move assignment operator
  // dest3.operator=(std::move(source2));
  dest3 = std::move(source2);
  std::cout << "(post-move) source2: " << source2 << ",\t dest3: " << 
    dest3 << std::endl;

  std::cin.get();
}