/*
 * Video #66: Type Punning - Getting around the C++ type system
 */

#include <iostream>

template<typename T>
struct Point2d
{
  /* In memory, a struct simply consists of its members and no other overhead*.
   * This means that in memory, the Point2d struct and a 2-member array of type
   * T look identical. We can take advantage of this fact and access the x and y
   * elements of a Point2d instance as if they were an array.
   * 
   * *Note that an empty struct will consist of a single byte of memory so that
   * it has a physical memory address
   */

  T x, y;

  // We can take advantage of type punning in another way by creating a getter
  // that provides access to x and y as if they were an array. In this way, no
  // memory is redundantly copied, but we can choose to interpret the underlying
  // data in different ways.
  T* as_array() { return &x; }
};

int main() {
  // Create a 2D point
  Point2d<float> pt = {1.0f, 10.0f};

  // Treat the Point2d as if it were a float array
  float* pos = (float*)&pt;
  std::cout << "(x=" << pos[0] << ", y=" << pos[1] << ")" << std::endl;

  // We could access the y-value in another (admitedly ridiculous way). We can
  // use a char pointer (a char is 1 byte in size) incremented by 4 bytes
  //(since a float is 4 bytes) and cast that to a float pointer. Derefercing
  // that pointer will give us y as a float.
  float y = *(float*)((char*)&pt + 4);
  std::cout << "y=" << y << std::endl;

  // Use Point2d::as_array to work with a Point2d instance as an array.
  float* point = pt.as_array();
  // We can update the x-value
  point[0] = 100.0f;
  std::cout << "(x=" << pos[0] << ", y=" << pos[1] << ")" << std::endl;
  // However, there are no bounds safegaurds, so the following would allow us to
  // write to memory that we really shouldn't be writing to.
  point[2] = 15.0f;

  std::cin.get();
}