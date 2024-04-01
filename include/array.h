#pragma once

// Include to get 'size_t'
#include <cstddef>

template<typename T, size_t S>
class Array
{
  // A custom array class that matches the interface of STL's std::array.
  public:
    Array() {}

    // It's work noting that we create no storage for the template argument 'S'
    // in our custom array class. At compile-time, but 'T' and 'S' are replaced
    // this function literally becomes "return 10;" in the case of the template
    // argument 'S' being 10, i.e. 'S' becomes a hard-coded value.
    // Note that we add the 'constexpr' keyword to tell the compiler that this
    // function can be evaluated at compile-time.
    constexpr size_t size() const { return S; }

    // A bare-bones implementation of the the index operator.
    // T operator[](int index) { return data_[index]; }

    // What's missing from index operator above?
    // 1) First, this returns by value, and this may not always be what we want.
    //  For example, this implementation doesn't allow for doing something
    // simple like "array[idx] = val;"
    // 2) What if want to declare our array as const? I.e. making it read-only?
    // 3) We use 'int' as the type for 'index', but this would allow 'index' to
    //  be negative, and int could possibly different sizes on different
    //  plaforms. To solve this, we replace 'int' with 'size_t'.
    // 4) There are no checks for an out-of-bounds index. Note that in the STL,
    //  this check is only implemented in Debug mode, not in Release.

    // To address 1) we'll return by reference instead of by value
    T& operator[](size_t index) { return data_[index]; }

    // To address 2), we'll overload the [] operator for a const Array
    const T& operator[](size_t index) const { return data_[index]; }

    // TODO: Add an iterator such that we can support range-based for loops.

    // TODO: Implement 'fill' and 'swap' utility functions.

  private:
    T data_[S];

};