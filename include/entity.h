#pragma once

#include <string>

class Entity
  // Entity will now be treated as an "interface class" by consisting
  // entirely of pure virtual methods.
{
  public:
    virtual std::string get_name() {return "Entity";}
    // get_name() is a "pure virtual method"
    // virtual std::string get_name() = 0;
};

class Player : public Entity
{
  public:
    Player(const std::string& name) : name_(name) {};
    std::string get_name() override { return this->name_; };

  private:
    std::string name_;

};

void show_name(Entity* entity);