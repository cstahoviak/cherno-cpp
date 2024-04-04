/*
 * Video #74: Benchmarking
 * 
 * NOTE: Build this code in Release mode and not Debug to get a better 
 * understanding of true performance.
 * 
 * We expect std::make_shared to be faster than std::shared_ptr because 
 * std::make_shared performs one heap-allocation, whereas calling the 
 * std::shared_ptr constructor performs two. See the link below for further
 * discussion:
 * 
 * https://stackoverflow.com/questions/20895648/difference-in-make-shared-and-normal-shared-ptr-in-c
 */

#include "utils.h"
#include "types.h"

#include <array>
#include <iostream>
#include <memory>

int main() {
  int value = 0;
  std::cout << "For loop addition:" << std::endl;
  {
    // Use a scope-based timer for benchmarking a simple for loop.
    Timer timer;
    int upper = 1'000'000;
    for (int i = 0; i < upper; i++) {
      value += 2;
    }
  }
  std::cout << "value: " << value << std::endl;

  // Benchmark the performance of 'make_shared' vs. 'shared_ptr' vs.
  // 'make_unique'
  const size_t n_vectors = 100'000;
  std::cout << "\nstd::make_shared<>():" << std::endl;
  {
    std::array<std::shared_ptr<Vec2>, n_vectors> shared;
    Timer timer;
    for (int i = 0; i < shared.size(); i++) {
      shared[i] = std::make_shared<Vec2>(0.0f, 0.0f);
    }
  }

  // std::shared_ptr
  std::cout << "\nstd::shared_ptr<>():" << std::endl;
  {
    std::array<std::shared_ptr<Vec2>, n_vectors> shared;
    Timer timer;
    for (int i = 0; i < shared.size(); i++) {
      shared[i] = std::shared_ptr<Vec2>(new Vec2(0.0f, 0.0f));
    }
  }

  // std::make_unique
  std::cout << "\nstd::make_unique<>():" << std::endl;
  {
    std::array<std::unique_ptr<Vec2>, n_vectors> unique;
    Timer timer;
    for (int i = 0; i < unique.size(); i++) {
      unique[i] = std::make_unique<Vec2>(0.0f, 0.0f);
    }
  }
  
}