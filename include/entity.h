#pragma once

#include <string>

#include "log.h"

class Entity
  // Entity will now be treated as an "interface class" by consisting
  // entirely of pure virtual methods.
{
  public:
    Entity() { std::cout << "Entity Created!" << std::endl; };

    // Use member initializer list. NOTE that member variables will be
    // initialized in the order that they are declared in the class, NOT the
    // order provided by the initializer list.
    Entity(int x, int y) : x_{x}, y_{y} {};

    // NOTE: DON'T use this constructor! It's inefficient!
    Entity(int x, int y, Logger::LogLevel log_level) : x_{x}, y_{y} {
      // Creating the Logger this way will effectively "throw away" the Logger
      // that was created when the Enity object is instantiated.
      logger_ = Logger(log_level);
    }

    // This constructor uses a member initializer list to prevent duplication in
    // creating the Entity's Logger. This is the CORRECT way to use member
    // initializer lists and is the most memory/time efficient.
    Entity(Logger::LogLevel log_level) : logger_{log_level} {};

    // Destructor
    ~Entity() { std::cout << "Entity Destroyed!" << std::endl; };

    virtual std::string get_name() { return "Entity"; }
    // get_name() is a "pure virtual method"
    // virtual std::string get_name() = 0;

    // Writing const after the fucntion name guarantees that the function will
    // "read-only", i.e. it will not modify any member variables.
    // NOTE: This method MUST be marked as const if it is expected to be
    // accessed by a const Entity reference (const Entity&) as in the
    // operator<< overload that we've defined.
    int get_x() const {
      // A const memeber method CAN modify mutable member vars
      debug_flag_ = true;
      return x_; };
    int get_y() const { return y_; };

    // In some cases it may be useful to define a non-const version of a getter.
    // Maybe I'll learn why later?
    // int get_x() {return x_; };
    // int get_y() {return y_; };

    // A function that cannot modify any member variables that returns a non-
    // modifiable pointer to a non-modifiable integer - C++ is kind of whack
    const int* const get_x_ptr() const { return x_ptr; };

  private:
    int x_;
    int y_;
    const int* const x_ptr = &x_;
    // One way to get around the fact that a member method marked const being
    // unable to modify member variables is to mark those variables as
    // "mutable" - this may be desirable in the case of debug info
    mutable bool debug_flag_ = false;

    // Give the Entity a Logger to demonstrate the efficiency of member
    // initializer lists
    Logger logger_;
};

// Cannot extend the << operator as a member-function of a class - it has to be
// a seperate function. The implementation of this function MUST be in
// entity.cpp otherwise I'll get an"multiple definition of operator<<" error
// because the implementation gets included in multiple translation units.
std::ostream& operator<<(std::ostream& stream, const Entity& e);


class Player : public Entity
{
  public:
    Player(const std::string& name) : name_(name) {
      std::cout << "Player named '" << name_ << "' created!" << std::endl;
    };
    std::string get_name() override { return this->name_; };

  private:
    std::string name_;
};

void show_name(Entity* entity);