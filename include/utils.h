/*
 * The utilities module.
 */
#pragma once

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