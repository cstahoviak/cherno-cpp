/*
* Video #82: Singletons.
*/

#include <iostream>

// This is what a "typical" singleton design pattern looks like.
class Singleton
{
  public:
    // Delete the copy constructor because a singleton cannot be copied
    Singleton(const Singleton&) = delete;

    // The public get() method is how we'll accesss and use the singlton
    static Singleton& get() { return s_instance; }

  private:
    // Constructor is marked private for a singleton class
    Singleton() {};

    // Create a static instance of the Singleton class that we'll return via
    // Singleton::get
    static Singleton s_instance;
};

// In a (possibly separate) cpp file file, we'd need a definition of the static
// member:
Singleton Singleton::s_instance;

// Let's create an actual singleton class that's not just an example of the
// singleton design pattern itself.
class Random
{
  public:
    // Delete the copy constructor because a singleton cannot be copied
    Random(const Random&) = delete;

    // TODO: Delete the assignment operator.

    // The core of a singleton, is the functionality defined by get().
    static Random& get() {
      // When the get() function is called for the first time, a single Random
      // instance will be instantiated. For subsequent calls to get(), the
      // instance will exist in static memory and exist for the lifetime of your
      // application.
      static Random instance;
      return instance;
    }

    // Allows is to get around getting a random number by having to call
    // Random::get::get_float() out in main(), and instead we can just do
    // Random.get_float(). This is referred to as "inderection".
    static float get_float() {return get().m_get_float(); }

  private:
    // Constructor is marked private for a singleton class
    Random() {};

    // The private interface of get_float()
    float m_get_float() { return m_random_float; }

    float m_random_float = 0.5f;
};

// Why not use a namespace instead of a singleton class? The sort answer is: we
// can. We could also just provide a declaration for get_float() via a header
// file and have the definition of get_float (and s_random_float) obfuscated
// away in a separate cpp file.
namespace RandomGenerator
{
  static float s_random_float = 0.6f;
  static float get_float() { return s_random_float; }
}

int main() {
  // Use the singleton
  Singleton& instance = Singleton::get();

  // Use the random number generator singleton
  float value = Random::get_float();
  std::cout << "random float: " << value << std::endl;

  // Use the random number generator namespace
  float value2 = RandomGenerator::get_float();
  std::cout << "random float: " << value2 << std::endl;

  std::cin.get();
}