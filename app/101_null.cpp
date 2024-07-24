/*
 * Video #101: NULL
 */

#include <iostream>

class Entity
{
  public:
    Entity() = default;

    const std::string& name() const { return name_; }
    void print_type() { std::cout << "Entity\n"; }

  private:
    Entity* parent_;
    std::string name_;
};

/** 
 * Let's try to understand why `entity->print_type()` in the example code below
 * works when `entity->name()` does not because `entity == nullptr`.
 * 
 * - To do this, we can look at how the Entity class would be implemented in C.
 * In C, since there are no classes, we would create `EntityData` as a struct and
 * then implement its member functions separately because structs in C cannot
 * have member functions.
 * - Surprisingly, this separation of data and member functions is exactly what 
 * the C++ compiler creates for us (without us realizing).
 **/

/**
 * @brief The data that the Entity class stores will be handled by the
 * EntityData class.
 */
struct EntityData
{
  EntityData* parent_;  // offset == 0
  std::string name_;    // offset == 8
};

/**
 * @brief In C++, the compiler converts member functions of a class to "regular"
 * free-floating functions (that exist outside of the class) that take in an
 * instance of the class as their first argument. That instance is referred to
 * as the `this` keyword!
 * 
 * @param self An EntityData instance (note that it's marked const).
 * @return const std::string& 
 */
const std::string& name(const EntityData* self) {
  return self->name_;
}

/**
 * @brief The print_type() member function can also be implemented as a 
 * stand-alone function, but note that `self` is not used anywhere in the
 * funtion. Thus, self will never be dereferenced and possibly attempt to
 * dereference an invalid (nullptr) pointer.
 * 
 * @param self Unused.
 */
void print_type(EntityData* self) {
  // Note that if self == nullptr, this has no effect on the follwing line.
  std::cout << "Entity\n";
}

int main()
{
  // Usually, we'd prefer to create a new Enity object on the stack
  // Entity entity;

  // But for this example, we'll create it on the heap. This would look like
  // Entity* entity = new Entity();

  // This didn't build in Cherno's example (throws an "uninitialized local
  // variable" error), but it build for me...
  // Entity* entity;

  // Create a NULL Enttity pointer
  Entity* entity = nullptr;

  // This will work if entity is nullptr. But why? See README for more detailed
  // explanation
  entity->print_type();

  // This creates a segmentation fault for me. For Cherno, he gets a "read
  // access violation" error: "this was 0x8." Not sure why I can't recreate
  // that... The reason for this is actually very intereting and is illuminated
  // by the offsetof() macro. We get "this was 0x8" because the string name_ is
  // at an offset of 8 relative to (Entity*)nullptr, i.e. 0 + 8 = 8.
  // std::cout << entity->name() << std::endl;

  /**
   * The offsetof() macro.
   * 
   * The offsetof() macro will give us the offset (in bytes) of a particular
   * member variable of a class or struct.
   */
  size_t offset = offsetof(EntityData, name_);
  std::cout << "Offset of EntityData.name_: " << offset << std::endl;

  // If we were to write offsetof() ourselves, it would look like (in C++)
  // ((::size_t)&reinterpret_cast<char const volatile...)

  // (in C) Working from the inside out, we cast 0 (NULL) to be an EntityData
  // pointer, then we get the memory address of name_ (relative to a starting
  // point of 0) and cast that to a size_t.
  size_t offset1 = (size_t)&(((EntityData*)NULL)->name_);
  std::cout << "Offset of EntityData.name_: " << offset1 << std::endl;
}