#pragma once

#include <iostream>
#include <cstring>

struct Vec2
{
  float x, y;

  Vec2(float x, float y) : x(x), y(y) {};

  // Write a simple Copy Constructor to keep track of when copying happens
  Vec2(const Vec2& other) : x(other.x), y(other.y) {
    std::cout << "Vec2 Copy Constructor invoked." << std::endl;
  }

  // If we don't use operator overloading, we would need to define a method that
  // allows us to add two Vec2s together. Reminder that marking the method as
  // "const" ensures that this method will not modify the member variables of
  // of the Struct.
  Vec2 add(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
  }

  // Use "operator overloading" to accomplish the same thing as above.
  Vec2 operator+(const Vec2& other) const {
    return Vec2(x + other.x, y + other.y);
  }

  // Use operator overloading to define scalar multiplication
  // TODO: Can I templatize this to extend to floats and doubles?
  Vec2 operator*(const int scalar) const {
    return Vec2(scalar * x, scalar * y);
  }

  // Use operator overloading to overload the == and != operators
  bool operator==(const Vec2 other) const {
    return x == other.y && y == other.y;
  }

  bool operator!=(const Vec2 other) const { return !(*this == other); }

};

// Cannot extend the << operator as a member-function of a class - it has to be
// a seperate function. The implementation of this function MUST be in
// types.cpp otherwise I'll get a "multiple definition of operator<<" error
// because the implementation gets included in multiple translation units.
std::ostream& operator<<(std::ostream& stream, const Vec2& vec);

class String
{
  // A bare-bones (non-modern) C++ string class.
  public:
    String(const char* string) {
      // Determine the size of the string
      size_ = std::strlen(string);

      // Create a buffer the same size as the string (+1 to account for null 
      // termination character, but doesn't seem to be necessary?)
      buffer_ = new char[size_];

      // Copy the value pointed to by 'string' into our buffer
      std::memcpy(buffer_, string, size_);

      // Manually ensure that the buffer ends in a null termination character
      buffer_[size_] = 0;
    }

    // The Copy Constructor that C++ supplies by default performes a shallow
    // copy of the members and looks something like: 
    // String(const String& other) : buffer_(other.buffer_), size_(other.size_) {};
    // Or in more exciting fashion:
    // String(const String& other) { std::memcpy(this, &other, sizeof(String)); }

    // If we wanted to prevent our String class from being copied, we could
    // delete the copy constructor (this is how unique pointers prevent
    // themselves from being copied).
    // String(const String& other) = delete;

    // Now we'll define our own copy constructor that performs a shallow copy of
    // the size (because it's just an int) and a deep copy of the buffer pointer
    String(const String& other) : size_(other.size_) {
        std::cout << "String Copy Constructor invoked." << std::endl;
        // Create the buffer as a 'new' char pointer
        buffer_ = new char[size_];
        // Copy the contents of the other string into the new buffer
        std::memcpy(buffer_, other.buffer_, size_);
    }

    ~String() {
      // The buffer was allcoated with new, therefore it must be deleted.
      delete[] buffer_;
    }

    // Declare the stream insertion operator overload as a 'friend' of this
    // class to allow the overloaded method to access private members of String.
    friend std::ostream& operator<<(std::ostream& stream, const String& string);

    // Overload the index operator to allow us to access elements of the string
    // by index. Ignore safety concerns that would check if the index is valid.
    char& operator[](const unsigned int index) { return buffer_[index]; }

  private:
    char* buffer_;
    unsigned int size_;
};

std::ostream& operator<<(std::ostream& stream, const String& string);