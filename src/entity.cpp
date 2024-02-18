#include <iostream>

#include "entity.h"

void show_name(Entity* entity)
{
  std::cout << entity->get_name() << std::endl;
}

// Takes a ostream reference and returns an ostream reference. Passing and
// returning by value will cause errors.
std::ostream& operator<<(std::ostream& stream, const Entity& e)
{
  return stream << "Entity(x: " << e.get_x() << ", y: " << e.get_y() << ")";
}