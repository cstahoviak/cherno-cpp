#include <iostream>

#include "entity.h"

void show_name(Entity* entity)
{
  std::cout << entity->get_name() << std::endl;
}