# cpp-weekly
Notes related to [Jason's Turner's C++ Weekly](https://www.youtube.com/@cppweekly/playlists) YouTube channel.

This "homework" series are not actually recommendations, i.e. it's not a _good idea_ to actually `auto` _all the things_. These homework exercises are more meant to illustrate the limitations of following the advice in the title, i.e. to what extent can I get away with using `auto`? And, more importantly, where am I explicitly restricted from declaring a variable type `auto`? For example, non-static data members of a class cannot not be declared using `auto`.

## C++ Homework

### [(Ep 297) C++ Homework: `auto` All the Things](https://www.youtube.com/watch?v=ZbmaeSoNDXc&list=PLs3KjaCtOwSb5GDEC-H79GBj9J-eJr9Qx&index=1&t=55s)

### [(Ep 299) C++ Homework: `const` All the Things]()

### [(Ep 301) C++ Homework: `constexpr` All the Things]()

### [(Ep 303) C++ Homework: Lambda All the Things]()

## Other Episodes

### [(Ep 332)](https://www.youtube.com/watch?v=aC-aAiS5Wuc) C++ Lambda vs `std::function` vs Function Pointer
- C++ lambba != `std::function` != function pointer
- __lambda__: _A C++ language construct for defining an anonymous function._
- `std::function`: _A "type-erased" wrapper around a callable object. Considered to be "more flexible" than a function pointer._
- Note: _"A capture-less lambda is implicitly convertible to a function pointer."_ -JT
- A simple lambda may look like
  ```
  auto add = [] (const double x, const double y) { return x + y; }
  ```
- We can declare a "place holder" for a function with the equivalent signature as the `add` lambda (note that this "place holder" function isn't actually callable yet and if invoked will throw a `std::bad_function_call`).
  ```
  std::function<double(const double, const double)> func;
  ```
- Making the following change makes this `std::function` object callable:
  ```
  std::function<double(const double, const double)> func{add};
  ```
- In many cases, we'd like to pass a callable as a function object. So let's write a function that accepts a callable using _function pointer_ syntax.
  ```
  double add(const double x, const double y) {
    return x + y;
  }

  double call(double (*f)(const double, const double)) {
    return f(1, 2);
  }
  ```
- Now, let's look at another way of writing `call` using `std::function`
  ```
  double call(const std::function<double(const double, const double)>& f) {
    return f(1,2);
  }
  ```

  ### [(Ep 333)](https://www.youtube.com/watch?v=xJSKk_q25oQ) A Simplified `std::function` Implementation
  - 
