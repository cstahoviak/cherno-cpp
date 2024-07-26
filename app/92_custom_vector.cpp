/*
* Video #92: Vector/ Dynamic Array - Making Data Structures in C++
*/

#include "types.h"
#include "vector.h"

#include <iostream>
#include <string>

int main() {
  // Lets think about some basic vector operations that our custom vector class
  // should support, e.g. instantiation and extending the vector.
  std::cout << "Use our custom 'Vector' container with std::string:" 
    << std::endl;
  {
    Vector<std::string> vec;
    vec.push_back("Cherno");
    vec.push_back("C++");
    vec.push_back("Series");
    vec.push_back("Vector");
    vec.push_back("Vector");
    vec.push_back("Vector");

    // Print the vector to verify that each push back succeeded
    print_vector(vec);
  }

  // Now let's use our custom Vec3 type with our Vector container
  std::cout << "\nUse our custom 'Vector' container with Vec3:" << std::endl;
  {
    /* For the following code snippet, Cherno's output looks like:
     * Copy
     * Destroy
     * Copy
     * Copy
     * Destroy
     * Destroy
     * Copy
     * Destroy
     * 
     * And mine looks like:
     * Copy (Assignment)
     * Destroyed
     * Copy (Assignment)
     * Destroyed
     * Copy (Assignment)
     * Copy (Assignment)
     * Destroyed
     * Destroyed
     * Copy (Assignment)
     * Destroyed
     * 
     * So where are the first two Copy/Destroy statements coming from?
     */
    Vector<Vec3> vectors;

    // Construct 3 Vec3 objects in the current stack frame and push them into
    // our Vector.
    std::cout << "\nPush back Vec3 objects by copy:" << std::endl;

    Vec3 vec0 = Vec3(1.0f);
    Vec3 vec1 = Vec3(2, 3, 4);
    Vec3 vec2;
    vectors.push_back(vec0);
    // vectors.push_back(vec1);
    // vectors.push_back(vec2);

    print_vector(vectors);
  }

  return 0;


  // Next, treat each Vec3 item as a temporary value (r-value) and use the
  // version of push_back that accepts an r-value reference.
  std::cout << "\nPush back Vec3 objects by r-value reference:" << std::endl;
  {
    /*
     * TODO: Cherno's output looks like the following:
     *
     * Move
     * Destroy
     * Move
     * Move
     * Destroy
     * Destroy
     * Move
     * Destroy
     * 
     * And mine looks like:
     * 
     * Move Assignment
     * Destroyed
     * Move Assignment
     * Destroyed
     * Move Assignment
     * Move Assignment
     * Destroyed
     * Destroyed
     * Move Assignment
     * Destroyed
     * 
     * For some reason, I have an extra occurance of "Move, Destroy" at the
     * beginning and I haven't been able to figure out why this is. See 25:40 in
     * the video.
     */ 

    Vector<Vec3> vectors;
    vectors.push_back({1.0f});
    vectors.push_back({2, 3, 4});
    vectors.push_back({});
    print_vector(vectors);
  }

  // Use Vector::emplace_back_inefficient to construct objects "in place" rather
  // than constructing them in the current stack frame and then "moving" them
  // into our Vector data storage.
  std::cout << "\nConstruct Vec3 objects in-place via " << 
    "Vector::emplace_back_inefficient:" << std::endl;
  {
    Vector<Vec3> vectors;
    vectors.emplace_back_inefficient(1.0f);
    vectors.emplace_back_inefficient(2, 3, 4);
    vectors.emplace_back_inefficient();
    print_vector(vectors);
  }

  // Use the "efficient" version of emplace_back that uses the "placement" new
  // keyword.
  std::cout << "\nConstruct Vec3 objects in-place via Vector::emplace_back:" 
    << std::endl;
  {
    Vector<Vec3> vectors;
    vectors.emplace_back(1.0f);
    vectors.emplace_back(2, 3, 4);
    vectors.emplace_back();
    print_vector(vectors);
  }
}