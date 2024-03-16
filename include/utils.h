/*
 * The utilities module.
 */
#pragma once

#include <chrono>
#include <iostream>

// Define a Macro - a TERRIBLE use of the preprocessor because WAIT will confuse
// anyone who comes across it anywhere in your code.
#define WAIT std::cin.get()

// A better use of a macro.
// #define LOG(x) std::cout << x << std::endl;

// Define a compiler varaible based macro that will effectively hide all of our
// logging code if that variable is not set.
#ifdef CS_DEBUG
  # define LOG(x) std::cout << x << std::endl;
#else
  #define LOG(x)
#endif

// This is effectively a wrapper around std::cout
template<typename T>
void print(T value) { std::cout << value << std::endl; }

struct Timer {
  // Timer is a scope-based timer utility that will capture the total time that
  // this struct is in scope.
  
  std::chrono::high_resolution_clock::time_point start;
  std::chrono::high_resolution_clock::time_point end;
  std::chrono::duration<float> duration;

  Timer() { start = std::chrono::high_resolution_clock::now(); }
  ~Timer() {
    end = std::chrono::high_resolution_clock::now(); 
    duration = end - start;

    float ms = duration.count() * 1000.0f;
    std::cout << "Timer took " << ms << "ms." << std::endl;
  }

};