# cherno-cpp
A repository for working through [the Cherno's C++ YouTube series](https://www.youtube.com/playlist?list=PLlrATfBNZ98dudnM48yfGUldqGD0S4FFb).

Why write in C++? Because we care about things like:
- Memory
- Performace
- Hardware Optimization

If you don't care about these things, don't choose C++!

This tutorial series will cover the following topics:
- [Introduction - How C++ Works](#introduction---how-c-works)
   - Welcome to C++ (1)
   - How the C++ Compiler Works
   - How the C++ Linker Works
   - How C++ Works
- [C++ Fundamentals](#c-fundamentals)
   - Variables (8)
   - Functions
   - Header Files
   - Conditions and Branching
   - Control Flow
   - Pointers
   - References
   - Classes vs. Structs
   - `static`
   - Enums
   - Destructors
   - Inheritance
   - Virtual Functions
   - Interfaces (Pure Virtual Functions)
   - Visibility
   - `const`
   - `mutable`
   - Member Initializer Lists
   - Ternary Operators
   - How to Create/Instantiate Objects
   - `new`
   - Implicit Coversion and the `explicit` Keyword
   - Operators and Operator Overloading
   - `this`
   - Copying and Copy Constructors
   - The Arrow `->` Operator
   - Local Static
   - `auto`
- [Memory Management in C++](#memory-management-in-c)
   - Object Lifetime (Stack/Scope Lifetime) (42)
   - Smart Pointers
   - Stack vs. Heap Memory
   - Type Punning (maybe put it here?)
   - Safety in Modern C++ and How to Teach It
- [Data Structures](#data-structures-in-c)
   - Arrays (30)
   - Dynamic Arrays
   - Optimizing the Use of `std::vector`
   - Static Arrays (`std::array`)
   - Multidimensional Arrays (2D Arrays)
   - Unions
   - Maps (`std::map` and `std::unordered_map`)
- [C++ Advanced Topics](#c-advanced-topics)
   - How to Deal with Multiple Return Values (52)
   - Templates
   - Macros
   - Function Pointers
   - Lambdas
   - Namespaces
   - Threads (maybe put it here?)
   - Sorting
   - Type Punning
   - Virtual Destructors
   - Casting
   - Dymamic Casting
   - Singletons
   - Argument Evaluation Order
   - Iterators
   - What Exactly is `NULL`?
- [Performance & Benchmarking](#performance--benchmarking)
   - Threads (62)
   - Timing
   - How to Make C++ Run Faster with `std::async`
   - How to Make your Strings Faster
   - Small String Optimizations
   - Track Memory Allocations the Easy Way
- [Storing Multiple Types of Data](#storing-multiple-types-of-data)
   - How to Deal with Optional Data (76)
   - Multiple Types of Data in a Single Variable
   - How to Store ANY Data
- [Move Semantics](#move-semantics)
   - l-values and r-values (85)
   - Move Semantics
   - `std::move` and the Move Assignment Operator
- [Workflow and Debugging](#todo-workflow--debugging)
   - Using Libraries (49)
   - Using Dynamic Libraries
   - Making and Working with Libraries
   - Conditional and Action Breakpoints
   - Precompiled Headers
   - Structured Bindings
   - Continuous Integration
   - Static Analysis
- [Writing Our Own Data Structures](#writing-our-own-data-structures)
   - Array (91)
   - Dynamic Array (Vector)
   - Writing an Iterator

## Introduction - How C++ Works

### Video #1: Welcome to C++ (What We'll be Learning)
- How C++ actually works.
- Memory and pointers.
- Memory "arenas", custom allocators, smart pointers, move semantics.
- Templates: _"If you know how to use templates well they're extremely powerful and will make your life a lot easier."_ - Cherno
- Data structures (and how to make them faster than the standard STL data structures).
- Low-level optimization via "compiler-intrinsics" and assembly.

### Video #6: How the C++ Compiler Works
- TODO:

### Video #7: How the C++ Linker Works
- TODO:

### Video #5: How C++ Works
- What we want to know: How to we go from source code (.cpp files) to an executable binary?
- Preprocessor statements (# statements, e.g. `#include`) happen before compilation.
   - `#include` statements pre-pend the contents of another file into your file.
- Every C++ application needs an "entry point", typically this is `main()`.
- Operators are just functions! Think of operators as functions.
- Header files do not get compiled. The contents of included files get compiled as part of the cpp files that they're included in.
- The Compiler creates an _object file_ (.obj) for every cpp file.
- The _linker_ "glues" the object files into an executable.
   - A linker error can happen when a symbol (e.g. a function name) that was "promised" to exist (e.g. via forward-declaration) cannot be resolved or found.
   - This error is referred to as an "unresolved external symbol."

## C++ Fundamentals

### Video #8: Variables in C++
- TODO:

### Video #9: Functions in C++
- Functions prevent code duplication.
- Each time a function is called in C++, the compiler generates a "call instructions"*. A call instruction creates a _stack frame_ for that function, meaning we have to push the function parameters and return address onto the _stack_. Additionally, we have to jump to a different part of our binary to execute a function, and then return to where it was called from. All of this is "expensive".
- *: this only happens if the compiler chooses not to "inline" your function.

### Video #10: Header Files
- Header files are used to store function and/or class __declarations__ (__not__ definitions).
- `#pragma once`: Only include this file once into a single "translation unit". A translation unit is a single cpp file.

### Video #12: Conditions and Branching in C++
- `if` statements consist of two parts:
   - The evaluartion of the conditional and the branch(es) that can be jumped to (jumping to a different part of memory).
   - "Optimized" code may attempt to avoid branching altogether to prevent jumping around in memory.

### Video #15: Control Flow in C++
- `continue`, `break`, `return`

### Video #16: Pointers in C++
- "Possibly the most important episode in the series!"
- raw pointers, not discussing _smart pointers_ today.
- A pointer is an integer that represents a memory address.
- Being "invalid" is a perfectly acceptable state for a pointer.
- `0`, `NULL` and `nullptr` mean the same thing when it comes to pointers.

### Video #17: References in C++
- References are really just an extension of pointers
- References are "pointers in disguise".
- References must "reference" existing variables, whereas pointers can be created as new variables.

### Video #19: Classes vs. Structs in C++
- Visibility of member variables:
   - struct: `public` by default.
   - class: `private` by default.

### Video #21: `Static` in C++
- __Context 1__: `static` keyword when used outside of a class or struct.
   - `static` effectively allows you to mark a variable as "private" for a specfic translation unit (cpp file).
   - This prevents any other translation unit (cpp file) from finding that `static` variable in the linking process via the `extern` keyword.
- __Context 2__: `static` keyword when used inside a class or struct.
   - A `static` member variable of a class/struct is the same across all instances of that class/struct, i.e. there will be only __one instance__ of the `static` member variable.
   - A `static` method of a class does not have access to the object itself, i.e. cannot access the `this` keyword.
   - static methods (and also variables?) cannot access non-static variables because static methods do not actually have a "class instance".

### Video #23: Enums in C++
- Enums provide a way to give a name to a value and organize groups of names and values that make sense together.
- `enum` vs. Enum class?

### Video #25: Destructors in C++
- The destructor applies to both __stack__ and __heap__ allocated objects.
- If you allocate an object via the `new` keyword, when you call `delete` on that object, the destructor will be called.
- When a stack-based object goes out of scope, the desctrutor will be called.
- Why write a destructor?
   - Any manually-allocated memory on the heap needs to be manually cleaned up in the destructor or you will create memory leaks.

### Video #26: Inheritance in C++
- A note on Constructors: Every constructor in the inheritance hierarchy gets called in the order of base-class -> derived-class.
- Destructors get called in the _reverse_ order!
- Polymorphism: Achieved either via function overloading or operator overloading, e.g. you can use the `+` operator to add two ints, two floats or even concatenate two strings.

### Video #27: Virtual Functions in C++
- Virtual functions allow us to override methods in sub-classes. A method marked as `virtual` in the parent class can be overridden in the child-class.
- Virtual functions implement "dynamic dispatch" via a "v-table". The v-table contains a mapping of all the virtual functions in the base-class to their overridden functions in the child-class.
- Marking a function as virtual tells the compiler to create a v-table for that function.
- If you want to override a function in the child-class, you __must__ mark the correspodning fucntion in the parent-class as `virtual`. 
- The `override` keyword should be used to mark the child-class method to indicate that it is overriding a virtual method of the parent class.
- Virtual functions come at the expense of creating a v-table, but in reality, the performance difference is negligible.

### Video #28: Interfaces in C++ (Pure Virtual Functions)
- The concept of a "pure virtual function" in a base class allows us to  define a base-class member function that does not have an implementation, thereby forcing sub-classes to implement that function.
- This is similar to an `abstractmethod` in python.
- An "interface class" consists entirely of "pure virtual methods" and cannot actually be instantiated.
- A sub-class of an interface class can __only__ be instantiated if it implements __all__ of the pure virtual methods defined by the parent-class.

### Video #29 Visibility in C++
- `private`: these member variables and function can (and should) only be accessed by the class itself
- `protected`: these member variables and function can (and should) only be accessed by the class itself and any sub-class.
- `public`: these member variables and function can (and should) only be accessed by any other class of function.

### Video #30: Arrays in C++
- TODO

### Video #33: `Const` in C++
- NOTE: This is where I picked up after the interview. I'm taking my time getting through the content now.
- A "promise" that something will not be changed (not actually strictly enforced).
- `const int* ptr`: value at pointer location cannot be changed, i.e. cannot do `*ptr = 100;`, but the pointer can be re-assigned to a new address.
- `int* const ptr`: The pointer cannot be assigned to a new address, but the value at the pointer location can be changed.
- `const int* const ptr`: The pointer cannot be re-assigned to a new address and the value at the pointer location cannot be changed.
- `void MyClass::func() const`: Guarantees that this function will not modify any member variables of `MyClass`, i.e. this function is "read-only".
- Rule of thumb: Mark any methods that are intended to be read-only as `const`, e.g. `void MyClass::func() const`.
- The `mutable` keyword allows `const` methods to modify member variables.

### Video #34: The `Mutable` Keyword in C++
- Two (very different) use cases: with `const` and with lambdas.
- The `mutable` keyword allows `const` methods to modify member variables.
- lambda (quick definition): a throw-away function that you can assign to a variable.

### Video #35: Member Initializer Lists in C++
- A way to initialize class member function via the contstructor.
- Member initializer lists are the most memory/time efficient way to construct
an object of a class that consists of non-primitive type members, i.e. members of other class types. For an example of this, see the `member_init.cpp` app that demonstrates how the Entity's Logger is effectively created twice (and thrown away once) when member initialization is used improperly.

### Video #36: Ternary Operators in C++
- Effectively syntatic sugar for an if statement.
- `<var> = <conditional> ? <value if true> : <value if false>`
- e.g. `std::string rank = (level >= MASTER_LVL) ? "Master" : "Novice"`
- Using a ternary operator to do something like this is actually _faster_ because of something called _Return Value Optimization_.
- In the example below, an empty string object called `rank` is created and then overriden with either "Master" or "Novice" once the conditional is evaluated. Using the ternary operator prevents `rank` from being created as an empty string object before being re-assigned.
```
std::string rank;
if (level >= MASTER_LVL)
   rank = "Master";
else
   rank = "Novice";
```
- Worth noting that ternary operators can be nested, but this can quickly become confusing to read and isn't recommended.

### Video #37: How to Create/Instantiate Objects in C++
- All objects that are created must occupy some memory.
- Memory is divided into two main areas: the __stack__ and the __heap__.
- __Stack__ objects have a pre-determined lifespan that is defined by the _scope_ that they are created in. Once that variable/object goes _out of scope_ , then the local _stack frame_ gets destroyed, i.e. that memory is freed.
- So, when should you create an object on the Stack? Whenever possible! Creating an object on the stack is typically the fastest and most "resourced managed" way to create an object in C++.
- The Stack is much smaller than the heap. The size of the Stack is platform-dependent, but is typically 1-2MB.
- __Heap__ objects don't behave in the same way.
- The `new` keyword creates an object on the Heap and returns a pointer to that object, e.g. `Entity* e = new Entity()`. This object does __not__ have a pre-determined lifespan and must be deleted manually using `delete`.
- Stack vs. Heap overview:
   - Performance: Heap allocation takes longer than Stack allocation.
   - Memory Allocation: Heap allocation requires _manual_ freeing of that memory - freeing memory isn't nicely managed the same way that it is for objects on the Stack. This can lead to _memory leaks_.
- So when should you create an object on the Heap?
  1. Is your object really, really big? (larger than the size of the Stack)
  2. Do you want to manaually control the lifespan of your object?
- If no to both 1. and 2. then create your object on the Stack!
- _Smart Pointers_ (which we'll get into later) provide a means to allocate an object on the Heap but with the memory-mangement advantages that come with Stack allocation.

### Video #38: The `new` Keyword in C++
- `new` finds a block of memory (via the _free list_) that is large enough to accommodate our needs, and returns a pointer to thart block of memory.
- `new` does two things:
   - Allocates the memory required to store the object.
   - Calls the constructor for that object.
- `new` is actually an operator, in the same sense that the `+`, `==` or `<<` (stream insertion) are operators. That means that `new` can be _overloaded_.
- So what does `new` do under the hood? It calls `malloc()`. The following two lines are _almost_ equivalent aside from the fact the `new` calls the `Entity` constructor, whereas the second line purely allocates memory and returns a pointer to that memory. This is just for instructional purposes, you don't want to be doing anything that looks like the second line.
```
Entity* e1 = new Entity;
Entity* e2 = (Entity*)malloc(sizeof(Entity));
```
- `new` and `delete` are an inseparable pair. __All__ newly allocated memory must eventually be deleted. This is handled in an automated way by _smart pointers_.
   - `new` and `delete` for standard objects.
   - `new[]` and `delete[]` for arrays.

### Video #39: Implicit Conversion and the `explicit` Keyword in C++
- Implicit Conversion allows C++ to convert between one type and another, so long as only a "single step" conversion exists between those two types.
- `explicit` __disables__ implicit conversion.
- Probably won't find myself using this very often, but good to know it exists and what it does.

### Video #40: Operators and Operator Overloading in C++
- Operators: `=`, `==`, `<<` (stream insertion), `&`, `&&`, etc.
- `new`, `delete` and `()` are also operators.
- "Operators _are_ functions!"

### Video #41: `this` keyword in C++
- `this` is a pointer to the current object instance that the member-method belongs to.
- Deferencing (getting the value or object stored at the pointer location) the `this` pointer looks like `this->x_` which is equivalent to `(*this).x_`.
- Can be used to pass the current object (or a pointer to the current object) to another function, e.g. `func(*this)` or `func(this)`.
- Don't ever `delete this`.

### Video #44: Copying and Copy Constructors in C++
- Copying is expensive and should be avoided if unnecessary.
- The _Copy Constructor_ is supplied by default by C++ and is implemented as a
_shallow copy_. This will create problems for any objects that have heap-allocated member pointers because the pointer itself will be copied. This results in pointer stored by the copied object pointing to the same memory address as the original object. When that memory is freed by the original object, attempting to free that same memory by the copied object will cause hard-to-diagnose errors.
- In order to implement a _deep copy_ of an object, we must rewrtite the Copy Constructor ourselves: `<Type>(const <Type>& other){}`
- __Best Practice__: Prefer passing objects by const reference (`const <type>&`) to prevent unecessary copying.

### Video #45: The Arrow Operator in C++
- The arrow operator `->` is used to _dereference_ a pointer.
- The following lines are equivalent (the () are required in the first line because of operator precedence, i.e. dereferencing must take place before accessing the member method):
```
(*ptr).member_method();
ptr->member_method();
```
- Because the `->` is an operator, it can be overloaded. This can useful if we choose to write our own scoped pointer class, e.g. `ScopedPtr`.
- Bonus functionality: The arrow operator can be used to determine the offset in memory of a particular member variable, e.g:
```
struct Vec3
{
   // Floats are 4 bytes in length
   float x, y, z;
}

int main() {
   // Starting at zero (nullptr) give me the offset of the member y
   int offset = (int)&((Vec3*)nullptr)->y;
   <!-- int offset = (int)&((Vec3*)0)->y; -->
   std::cout << offset << std::endl;
}

Terminal Output:
4
```

### Video #48: Local Static in C++
- Can declare a variable as `static` in a local scope - this is different from the other two use cases of static that we've seen already.
- Declaring a variable as `static` within a local scope (e.g. within a function) restricts access to that variable to that local scope, but extends its lifetime to the lifetime of the program.
```
void f() {
   static int i = 0;
   i++;
   std::cout << "i: << i << std::endl;
}

int main() {
   f();
   f();
   f();
}

Terminal Output:
i: 1
i: 2
i: 3
```
- Often use of local `static` variables are discouraged.
- One possible use case is for _Singleton_ classses, i.e. a class that should only have one instance in existance.

### Video #56: The `auto` Keyword in C++
- `auto` allows C++ to become a psuedo _weakly-typed_ language.
- When to use `auto`?
   - For very long types that it's annoying to write out and you don't want to `using` to create an alias.
   - For iterators in for loops:
```
std::vector<std::string> strings;

// This is ugly and long
for (std::vector<strd::string>::iterator it; strings.begin(), it != strings.end(), it++) {
   // do something
}

// This is much cleaner and easier to read
for (auto it; strings.begin(), it != strings.end(), it++) {
   // do something
}
```
- If you need a reference, use `auto&`.

## Memory Management in C++

### Video #42: Object Lifetime in C++ (Stack/Scope Lifetimes) in C++
- Will be taking a look at the lifetime of stack-based variables.
- Each time a new scope is _entered_, a new _stack frame_ is pushed onto the stack. The stack frame consists of any variables declared within that scope (and possibly other data?) When the scope is exited, that stack frame is deleted and the memory on the stack is freed.
- What is meant by _scope_? Basically anything declared within `{}`.
- All stack-based variables/objects have a scope-based lifetime, i.e. once a stask-based variable/object goes out of scope, it's memory is freed.
- __Common mistake__: Attempt to create a stack-based variable within a function and then return a pointer to that variable. Once the function returns and that variable goes out of scope, that variable no longer exists and the pointer that is returned now points to a freed memory location that doesn't contain the data we expect it to.
```
int* create_array(const int size) {
   // This creates an array on the stack (which is scope-based)
   int array[size];
   return array;
}
```
- How can take advantage of the lifespan of stack-based (scope based) variables? Yes. "Scoped" classes like _smart pointers_ and _scoped locks_ take advantage of this.
- A Smart Pointer is effectively a wrapper around a raw pointer that heap-allocates some memory on creation and then deletes that pointer upon destruction (when the smart pointer itself goes out of scope?)
- Mutex Locking: In the context of threading, a scoped mutex lock allows us to "lock" a function upon entry (and unlock at exit) such that mutliple threads cannot access the function (and also the data manipulted by that function?) at the same time.

### Video #43: Smart Pointers in C++
- `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- `new` allocates memory on the heap and `delete` us used to free it.
- Smart pointers are a way to abstract the the `new`/`delete` paradigm away. Some programmers even go so far as to say you should _never_ use the `new` and `delete` keywords.
- Smart pointers are effectively wrappers around raw pointers.
- When you _make_ a smart pointer, it will call `new` and allocate memory, and then (based on which type of smart pointer you use) that memory will automatically be freed when the smart pointer goes out of scope.
- A `std::unique_ptr` is a _scoped pointer_ that cannot be copied.
- A `std::shared_ptr` stores a reference count and the object will only be deleted when that reference count goes to zero. Each time a new `shared_ptr` is made to an existing object, the reference count increases by one.
- A `std::weak_ptr` does not increase the reference count. Having a `weak_ptr` to an object is basically a way of saying "I want to know if this object exists, but I don't want to be the _reason_ that it exists or continues to exist."

### Video #54: Stack vs. Heap Memory in C++
- The Stack has a much smaller pre-defined size (~2MB), whereas the Heap is much larger. __Both__ exist in RAM, however the Stack may be _hot_ in the _cache_ because it is being accessed more frequently.
- Each program/process has its _own_ Stack and Heap.
- Each thread will create its own stack, but the heap is shared among threads (hence the need for thread-safety in multi-threaded applications). 
- Stack vs. Heap allocation:
```
// Allocate an int and an int array on the stack
int value = 10;
int array[10];

// Allocate an int and an int array on the heap
int* heap_value = new int;
*heap_value = 10;
int* heap_arr = new int[10];

// Must manually free heap-allocated memory
delete heap_value;
delete[] heap_arr;
```
- __Reminder:__ The lifetime of a stack-allocated variable is scope-based - whenever a scope is exited, all stack-allocated memory within that scope is freed.
- _Freeing_ memory on the stack is the same thing as resetting the stack pointer back to the beginning of the stack.
- Heap allocation via the `new` keyword effectively calls `malloc()` under the hood and returns a pointer to a free portion of memory that is maintained by the _free list_.
- Heap memory `==` _dynamic_ memory.
- __Takeaway:__
   - Allocating memory on the stack is effectively one CPU instruction, whereas allocating on the heap is _much_ more expensive: call `new` -> call `malloc` -> consult the _free list__ -> update the _free list_ -> ... -> eventually delete the memory.
   - The performance difference _is_ the allocation. Access _after_ allocation is approximately equivalent (_cache misses_ for heap-allocated memory can be the difference here).

### Video #71: Safety in Modern C++ and How to Teach It
- _Safe_ programming aims to prevent things like crashes, memory leaks (forgetting to free heap-allocated memory) and access violations. This video will focus on pointers and heap allocation.
- Why do we care? Because we want to write real-time, performance-critical production C++ code.
- With C++11, _smart pointers_ were introduced to support this goal. In reality, the entire goal of smart pointers is to automate the use of `delete`.
- Note: `shared_ptr` is __not__ thread safe. Why?

### Video #84: Track Memory Allocations the Easy Way in C++
- TODO:

## Data Structures in C++

### Video #46: Dynamic Arrays in C++ (std::vector)
- Time to get accustomed with the standard template library (STL)!
- `std::vector` is actually a dynamic array (list) - _dynamic_ in the sense that it can be resized, e.g. extended, appended to, etc.
- When you exceed the allocated size of a particular `std::vector` instance, it creates a new array in memory, copies the contents of the original vector into the new vector and deletes the original vector. In practice, this re-allocation can occur quite often and can result in performance losses.
- Dynamic arrays store their memory contiguously (in line, not fragmented in memory). This is optimal for any operation that requires iterating over the vector.
- When this can become non-optimal is when you anticipate that your vector will need to be resized frequently because this will require copying the objects themselves over and over. _Moving_ instead of cpying largely solves this issue, but not entirely because there is still come copying involved.
- __Question:__ Should I be storing pointers to heap-allocated objects in my vectors (lists), or should I store the stack-allocated objects themselves?
- __Answer:__ It depends. The primary consideration is that it is technically more optimal to store the objects themselves in the list because storing the objects themselves requires that the memory allocated for those objects is inline (contiguous). A vector of pointers can be optimal in the case when thart vector may need to be resized frequently.
__Best Practice:__ Prefer passing dymanic arrays by const reference to avoid uncessary copying.
- `std::array` allocates its memeory on the stack, whereas `std::array` allocates its memory on the heap.

### Video #47: Optimizing the use of std::vector in C++
- We can use `std::vector.reserve(n)` to allocate enough memory for `n` objects _without_ actually wasting time constructing those objects before we're ready to push them onto the vector.
- We can also use `std::vector.emplace_back()` to construct the object being added to the vector _in place_ (at the location in memory allocated by the vector) as opposed to creating it in the local stack frame and then having to copy it to the memory location allocated by the vector as is done by `std::vector.push_back()`.

### Video #57: Static Arrays (`std::array`) in C++
- Static arrays have a pre-defined size and their size __cannot__ be changed.
- Very similair to C-style arrays: `int arr[10];` can be rewritten as a static array like `std::array<int, 10> arr;`.
- __Question:__ How do we take a `std::array` as a function argument if we don't know the size?
```
// Template that doesn't assume type or size
template<typename T, size_t s>
void f(std::array<T, s> arr) {
   for (const auto& item : arr) {
      // do stuff
   }
}

// Template that assumes the type (and int array), but not the size
template<size_t s>
void f(std::array<int, s> arr) {
   for (const int& item : arr) {
      // do stuff
   }
}
```
- `std::array` allocates its memory on the stack, whereas `std::vector` allocates on the heap.
- __Best Practice:__ Prefer `std::array` to _old_ C-style arrays.
   - `std::array` supports STL features like `size()` and iterators (`begin()` and `end()`).
   - Can apply STL algos like `std::sort` to `std::array`.
   - No additional performance cost associated with `std::array` since the `size` is stored as a template argument.

### Video #64: Multidimensional Array (2D Arrays) in C++
- n-dimensional arrays. When to use them. When _not_ to use them!
- An array is actually just a pointer to the beginning of the array. Extending that concept to a 2D array would mean that a 2D array is actually just an array of pointers, where each pointer is the starting location of a single array of the larger 2D array.
- Allocating a 2D array might look something like `int** arr_2d = int*[50];`. We can read `int**` as `(int*)*` or "a pointer to a collection of integer pointers." Each element of `arr_2d` will be an integer pointer, so we can do something like `arr_2d[idx] = nullptr;`
- Deleting a multidimensional array isn't trivial either. Say we declare the following 5x10 2D array then attempt to delete it:
```
int** arr_2d = new int*[5];
for (int i = 0; i < 5; i++) {
    arr_2d[i] = new int[10];
  }
delete[] arr_2d;
```
That will only delete the array of pointers pointing to each of the 50 arrays of integers. The integers themselves will not be deleted and become a memory leak. What we have to do to delete a 2D array without leaking memory is:
```
for (int i = 0, i < 5; i++) {
   delete[] arr_2d[i];
}
delete[] arr_2d;
```
- In the example above, there is __no guarantee__ that each of the 5 blocks of 10 integers will be contiguous in memory. Which can make our array slower to iterate over than an array that had all 5 blocks of 10 integers allocated contiguously in memory.
- __Best Practice:__ Because of this issue, it may not be a good idea to use 2D arrays for things like images or textures where we want access to each pixel to be fast. So instead, prefer to store an image as a 1D array and be smart about how you iterate over it.

### Video #67: Unions in C++
- A Union is a bit like a class or struct type, but it can only occupy the memory of one member at a time. In other words, ... (these are kind of confusing).
- "Put differently, A union of multiple members places each member at the same starting address. This greatly saves on memory used, but the downside is that you can only use one member at a time because they all start at the same address. As you can imagine these were enormously helpful in the 90's when memory was limited. They still have use cases today, but you have to be careful because it can feel like you're' working with separate unique variables when in reality you're working with different variables all occupying the same starting address. Unions can tend to trip you up if you're not careful leading to really wacky bugs but they can be a powerful tool if used seldomly and correctly."
- Useful for when:
   - We want to give two different names to the same variable, e.g. it may be useful to think of a three-element vector (x, y, z) as a color (RGB) where x maps to R and so forth.

### Video #100: Maps (`std::map` and `std::unordered_map`) in C++
- TODO

## C++ Advanced Topics

### Video #52: How to deal with Multiple Return Values in C++
- How to deal with _tuples_ and _pairs_.
- In C++, a function can return only _one_ value.
- __Option 1:__ One way to get around this is to have your function return `void` and instead pass in references to the objects you want to assign and set them via reference instead of actually returning anything.
```
void f(std::string& out_str1, strd::string& out_str2) {
   out_str1 = "one";
   out_str2 = "two";
}

int main() {
   std::string a, b;
   f(a, b)
}
```
- __Option 1b:__ As an alternative to passing by reference, we can pass a pointer, and this allows us the addional option of passing `nullptr` when we don't actually want to set that value.
```
void f(std::string* out_str1, strd::string* out_str2) {
   if (out_str1) { out_str1 = "one"; }
   if (out_str2) { out_str2 = "two"; }
}

int main() {
   std::string a, b;
   f(nullptr, &b)
}
```
- __Option 2:__ We can return a heap-allocated `std::array`. Not really great option. Cherno isn't a fan of this method, or of using `std::array`.
```
#include <array>

std::array<std::string, 2> f() {
   return std::array<std::string, 2>("one", "two");
}

int main() {
   std::string* result_array = f();
}
```
___Option 3:__ Using _Tuples_ and _Pairs_.
- Ugly because accessing members of a tuple can only be done via `std::get<index>(tuple_var)` or `tuple_var.first` and we may want to be more explicit that this and actually name the members of the tuple for the sake of code readabilty.
```
#include <tuple>

std::tuple<std::string, std::string> f() {
   return std::make_pair("one", "two")
}

int main() {
   std::tuple<std::string, std::string> result = f();
   // Now get the first (index zero) string from the tuple (2 options)
   std::string first = std::get<0>(result);
   std::string first = result.first;
}
```
- __Option 4:__ (Cherno's favoite) create a struct (a _named tuple_ in Python) that excplicitly contains the items that we want to return.
```
struct FileInfo {
   std::string directory;
   std::string filename;
   std::string extension;
}

FileInfo f() {
   // Take advatage of "implicit conversion to create the FileInfo object
   return {"local_dir", "my_file", "txt"};
}

int main() {
   FileInfo file_info = f();
   filename = file_info.filename;
}
```

### Video #53: Templates in C++
- A template allows us to get the compiler to write code for us based on a set of rules.
- In `template<typename T>` the keywords `typename` and `class` can _almost_ be used interchangeably. But `typename` is preferred.
- At compile-time, a templated function only gets created (and linked) for the particular types that it's actually called within the source code.
- If a templated function is _never_ called in your code, the the compiler never actually creates any versions of the function, and it's possible to have errors in a templated function that can go undetected.
- The STL (Standard _Template_ Library) is a collection of standarized templated classes.
- __Best Practices:__ When to use templates:
   - Logging systems, buffers than need to contain various types.
- __Best Practices:__ When not to use templates:
   - ...

### Video #55: Macros in C++
- Macros allow us to use the _pre-processor_ to automate, "macro-ize", some aspects of our code.
- All `#` statements are known as _preprocessor directives_. The Preprocessor step comes before compilation.
- Templates v. Macros:
   - Templates get "evaluated" at compile-time.
   - Macros are evaluated in the preprocessor step and strictly consist of "pure text replacement" which comes before compilation.
- Cherno doesn't like overusing macros.
- ###__ Finish adding a command line CMake variable to enable/disable macros in my code.

### Video #58: Function Pointers in C++
- This video will focus on C-style _raw_ function pointers.
- Function pointers allow us to assign a function to a variable. Allows us to apply _logic_ to functions and pass functions as arguments to other functions.
- Since functions are effectively just a set of instructions stored somewhere within our binary (executable), the start of those instructions will have a memory address. Thus, we can create a function pointer like:
- __Lambdas__ are functions that are _anonymous_ functions that are declared inline that can be useful when you don't want to define a separate function.

### Video #59: Lambdas in C++
- Anywhere that you use or require a function pointer in C++, you _can_ use a lambda instead. But when is it good idea to do so?
- Declaring a lambda can look like:
```
auto lambda = [ captures ]( params ) { body };
auto lambda = [ captures ] { body };
```
- _Captures:_ 
   - `[a, &b]` captures `a` by copy and `b` by reference.
   - `[this]` captures the current object (`*this`) by reference.
   - `[&]` captures all _automatic_ variables used in the body of the lamda by reference and the current object by reference if it exists.
   -  `[=]` captures all _automatic_ variables used in the body of the lamda by copy and the current object by reference if it exists.
   - `[]` captures nothing.

### Video #61: Namespaces in C++
- Standard `C` does not support namespaces and so often times in C and C++ compatible libraries, like OpenGL, you'll see function names that have prepended the library name, e.g. `gl_get_vertex()`
- Namespaces exist to avoid naming conflicts. That's really it.
- `::` is the _scope resolution_ operator.
- Classes are themselves namespaces.
- You can create an alias for a namespace that may be too long to use efficiently, e.g. `using rlln = ReallyLongLibraryName;`
- Namespaces can be nested, e.g. `outer_ns::inner_ns::func()`
- Can do `namespace ns_name::name` since C++17.
- __Best Practice:__
   - Avoid `using namespace std` at all costs!
   - If you _must_ `using namespace` try to confine it to as small a scope as possible. Only as a last resort, use it at the top-level of a file.
   - NEVER `using namespace` in a header file! This is an easy way to create naming conflicts.

### Video #65: Sorting in C++
- `std::sort` is C++'s built-in sorting algorithm.
- See `app/sorting.cpp` for an example using `std::sort`.

### Video #66: Type Punning in C++
- Even though C++ is a _strongly-typed_ language, _type punning_ is just a fancy way of getting around the type system of C++. 
- Something that C++ is really good at is raw memory operations (memory maipulation), and we can take advantage of that to do some kind of ridiculous operations. See `app/type_punning.cpp` for an example.
- This can get us into trouble most of the time, but it can also be incredibly powerful. For example, type punning is used in Quake's notoriously fast inverse square root function - it converts a float into a long in order to use bit manipulation.

### Video #68: Virtual Destructors in C++
- Virtual destructors are useful when dealing with _polymorphism_.
- Remember the order of operations when it comes to instantiating and destroying an instance of a derived class - what we'll notice for the derived
class is that the Base constructor is called first, followed by the Derived
constructor. When the Derived instance is destroyed, the reverse order occurs.
- In order to _guarantee_ that the Base destructor is called, we can make the Base destructor as `virtual` (see `app/virtual_destructors.cpp` for an example).
- __Best Practice:__ When creating an class that we intend to be extended, i.e. derived from or sub-classed, we __need to__ declare its destructor as `virtual`. Otherwise, we cannot _safely_ extend that class in any case where we want to treat the derived class as if it were an instance of the base class, e.g. when passing a derived object to a function that may delete the derived instance via a base class pointer.
__Best Practice:__ [When should we __not__ use a `virtual` destructor?](https://stackoverflow.com/questions/300986/when-should-you-not-use-virtual-destructors)
   1. When we have no intention on deriving from the class.
   2. The class will never be instantiated on the heap.
   3. No intention to delete an derived instance via a base-class pointer. (But how can know that the codebase won't be extended in some way in the future in such a way that would delete a derived instance via a base class pointer?)
__Guideline #4:__ (Herb Sutter) "A base class destructor should be either `public` and `virtual`, or `protected` and nonvirtual."

### Video #69: Casting in C++
- C-style vs. C++ style casting. C style casts are simple and look something like:
```
double a = 5.25;
double b = (int)a + 5.3    // b = 10.3
```
- C++ style casts are different and include `static_cast`, `reinterpret_cast` (i.e. type punning), `dynamic_cast` and `const_cast`. C++ style casts don't actually do anything that C-style casts can't achieve, but they are more or less syntactical sugar on tope of C-style casting.
- `static_cast` helps to avoid removing constness that can be easily done through C-style casting.
- Say we have multiple derived classes from a single base class, and we're using a base class pointer to deal with the derived objects. A `dynamic_cast` can help us determine which derived type we're actually working with:
```
class Base { ... }
class Derived : public Base { ... }
class AnotherDerived : public Base { ... }

int main() {
   Derived* derived = new Derived()
   Base* obj = derived;
   // 'another' will evaluate to NULL because obj is not a AnotherDerived instance
   Derived* another = dynamic_cast<AnotherDerived>(obj); 
}
```

### Video #73: Dynamic Casting in C++
- Dynamic casting is a C++ style cast that as somewhat of a "safety net" which ensures that the casting we're doing is "valid".
- `dynamic cast` can only be used when Runtime Type Information (RTTI) is enabled.
- If RTTI is enabled, dynamic casting happens at runtime, not at compile time which means it comes with some performance cost.
- Other _managed_ langagues, like Python, have function like `isinstance()` to achieve the same behavior.
- See example in README from ### Video #69__ for how the failure of a `dynamic_cast` can be useful.

### Video #82: Singletons in C++
- A _singleton_ (a type of _design pattern_) is a class (or struct) that you intend to only ever have a single instance of.
- Examples of types of singleton classes:
   - A random number generator: Typically, we instantiate a random number generator once with a seed and then use that single instance (and seed) to generate sequences of random numbers.
   - A renderer:
- Singleton classes really just behave like a namespace, i.e. a single class is just a set of "global" variables and static functions that may (or may not) act upon those global variables.
- Worth noting one important functional difference between a namespace and a singleton class. In a namespace, all of the data is initialized (loaded into memory when the program first starts). This might be undesirable sometimes when we don't want all the data initialized until we actually need it. In contrast, singleton instances are only loaded during the first call to the `Get()` method.
- See tamasdemjen4242's comment for even more detail on the functional difference between singleton classses and namespaces, including thread-safe vs. non-thread-safe behavior.
- See `app/singleton.cpp` for an example.

### Video #88: Argument Evaluation Order in C++
- Consider the following simple example. What do we think will be printed? It turns out that in C++, this toy scenario results in _undefined behavior_, i.e. the behavior will be different from compiler to compiler.
```
void print_sum(int a, int b) {
   std::cout << a << " +  b << " = " << a + b << std::endl;
}

int main() {
   int val = 0;
   // Any of the following will produce "undefined behavior".
   print_sum(val++, val++);
   print_sum(++val, ++val);
}
```
- Note that the C++ compiler can evaluate certain expressions at compile-time, e.g. the C++ compiler is smart enough to replace `int a = 1 + 2;` with `int a = 3;` at compile-time rather than do the sum operation at runtime.
- In C++17, the C++ standard added rules for the evaluation of _postfix-expressions_, e.g. the post-increment operator `++`, that state that multiple post-fix expressions must be evaluated sequentially (rather simultaneously at compile-time) but this rule doesn't actually lead to a deterministic evaluation of `print_sum(val++, val++);`.

### Video #93: Iterators in C++
- Iterators are used to traverse data structures, and if we're writing our own
data structures, we probably want to support functionality like idexing and iteration.
- _Range-based_ for loops (avaible since C++11) are made possible by iterators.
`std::vector` implements both the `begin()` and `end()` functions that each return an _iterator_ that points to a particular position (the beginning and the _past-the-end_ element) in the vector.
```
std::vector<int> values = { 1, 2, 3, 4, 5 };
for (int& val : values) {
   std::cout << "value: << val << std::endl;
}
```
- Traversing a container by using its iterator explicitly is also possible, but less common because a range-based iteration is essentially shorthand for this. But in some situations, e.g. erasing or inserting new elements, you may want to manipulate the iterator.
```
for (std::vector<int>::iterator it = values.begin(); it != values.end(); it++) {
   // Dereference the iterator (bc it's a pointer) to get the value
   std::cout << *it << std::endl;
}
```
- See `app/93_iterators.cpp` for more examples, including iteration over non-indexable types, e.g. an unordered map (dictionary), via _structured bindings_.

### Video #96: Intro to Binary and Bitwise Operators in C++
- TODO

### Video #97: Bitwise AND, OR, XOR and NOT (&, |, ^, ~) C++
- TODO

### Video #101: What Exactly is `NULL`?
- TODO

## Performance & Benchmarking

### Video #62: Threads in C++
- Parallelization!
- Use `std::thread` to start some process, e.g. call a function, in a new thread.
- Use `std::thread::join` to wait for a worker thread to complete before resuming execution of the current thread, i.e. the thread that the worker thread was kicked off from.
- See `app/threading.cpp` for an example.

### Video #63: Timing in C++
- Since C++11, we have `std::chrono` to help us with timing, i.e. understanding how much time has elapsed between various lines of code.
- See `app/threading.cpp` to see how the `Timer` struct is used as a scope-based (lifetime based) timer to function profiling.
- The topic of _benchmarking_ will come later and will be more in depth. Will discuss _instrumentation_, i.e. modifying source code to contain profiling tooling.

### Video #74: Benchmarking in C++
- Performance differences between `std::make_shared` vs. `std::shared_ptr<type> (new type)` vs. `std::make_unique`.
- Important to perform this benchmarking in Release mode and __not__ Debug.
- Note that we expect `std::make_shared` to be faster than `std::shared_ptr` because `std::make_shared` performs one heap-allocation, whereas calling the `std::shared_ptr` constructor performs two. But as per the results of `app/benchmarking.cpp`, this isn't always true.

### Video #79: How to Make C++ Run Faster with `std::async`
- How can we take advantage of parallel processing, i.e. use multiple CPU cores?
- MSVS supports an interesting visualization called "Parallel Stacks".2
- The following is an example snippet from Cherno's game engine that will asynchronously load a list of textures in parallel.
```
#include <future>
#include <string>

static std::mutex s_meshes_mutex;

// Note that filepath is passed by copy because there's a possibility that the
// 'mesh_filepaths' variables from 'EditiorLayer::LoadMeshes()' may have gone
// out of scope while this function is still being called asynchonously.
static void load_mesh(std::vector<Ref<Mesh>>* meshes, std::string filepath) {
   auto mesh = Mesh::load(filepath)

   // Q: Can we actually 'push_back' onto a vector concurrently? No, this is
   // where "mutuex" and "locks" come into play in order to "lock" our resource
   // (the vector) while one thread accesses/modifies it to prevent another
   // thread from doing the same.
   
   std::Lock_guard<std::mutex> lock(s_meshes_mutex);
   meshes->push_back(mesh);

   // Note that std::Lock_gaurd is scope-based and will "release" the lock on
   // the s_meshes_mutex once the lock goes out of scope (the end of this 
   // function).
}

class EditorLayer : Layer
{
   public:
      enum class PropertyFlag
      {
         None = 0,
         ColorProperty = 1
      };

      EditorLayer();
      virtual ~EditorLayer();
      ...

   private:
      std::vector<std::future<void>> m_futures;
}

void EditiorLayer::LoadMeshes() {
   std::ifstream stream("data/models.txt);
   std::string line;
   std::vector<std::string> mesh_filepaths;
   while (std::getline(Stream line)) {
      mesh_filepaths.push_back(line);
   }

   // Load each mesh in serial
   for (const auto& filename : mesh_filepaths) {
      m_meshes.push_back(Mesh::load(file));
   }

   // Load each mesh in parallel
   for (const auto& filename : mesh_filepaths) {
      // std::async actually returns a std::future object, and we need to store
      // that "future" object. Why? ...
      m_futures.push_back(
         std::async(std::launch::async, load_mesh, &m_meshes, file));
   }
}
```

### Video #80: How to Make Your Strings Faster in C++
- TODO:

### Video #83: Small String Optimizations in C++
- TODO:

## Storing Multiple Types of Data

### Video #76: How to Deal with Optional Data in C++
- New to C++17 is `std::optional`.
- `std::optional<T>` __cannot__ be used with references. However,`boost::optional<T>` can handle references. This is very helpful if you want to check for existence of a bigger type in a map like `boost::optional<const Element&> GetElementAtPos(int x, int y)`. With `std::optional` you cannot do that and would have to return a pointer. The reason why it's unavailable in `std` is a bigger topic itself and you can read more online.
- `value_or(default_value)` is also designed with backwards compatibility in mind. If new code parts want to use `std::optional<T>`, but need pass `T` to an old method (where a magic value represents "not set") you can pass `value_or(magic_value)` to it to still be compatible with this old code part.
- `boost::optional` brings this concept even further and provides a constructor `boost::optional<T>(bool isSet, T value)` that can be used to filter out magic values on construction. So if an old method returns `T`(with either a value or a magic value "not set") you can initiate your variable like `boon  b.st::optional<T>(result != magic_value, result)`. This constructor is sadly not available in `std::optional` though.

### Video #77: Multiple Types of Data in a Single Variable in C++
- New to C++17 is `std::variant`. Similar `std::optional` in the sense that is allows us to not worry so much about the underlying data type, and be more concerned with if that data is actually available or not.
- Allows us to create a variable that can be one of multiple types, e.g. we can declare a value that will either be a string or an int:
```
#include <variant>

std::variant<std::string, int> data;
```
- We can use `std::variant::index` to determine which type the data _actually_ is. In the example above `data.index()=0` means that `data` is a `std::string` and `data.index()=1` meands that `data` is an `int`.
- Alternatively, we can use `std::variant::get_if` to return a pointer to our data that will be `NULL` if the data is not the type we requested.
```
auto value = std::get_if<std::string>(&data);
```
- Are variants just "type-safe unions"? Short answer: not exactly. The `sizeof()` a union will be equal to the size of its largest type, whereas the size of a variant will be the combined size of all of its types, e.g. `sizeof(std::variant<std::string, int>) == sizeof(std::string) + sizeof(int)`.
- __Best Practice:__ Prefer variants to unions because they are _type safe_.
- Could use `std::variant` as an alternative to `std::optional` when we want to be more specific about what may have gone wrong when evaluating a function. See `app/optional.cpp` for an example of using `std::variant` to possibly return an error code enum type.

### Video #78: How to Store ANY Data in C++
- New to C++17 is `std::any`. We can use it store _any_ type of data in a single variable (technically possible with a `void*`, but this is a C++17-safe way of doing it).
- Remember, `std::variant` is effectively a type-safe `std::union`, but they differ in size. However, `std::any` behaves differently for "small" and "large" types. For small types, `std::any` stores its data as if it were a union, but for large types (< 32bytes on MSVC), `std::any` will perform a dynamic memory allocation to store the larger data type (unecesary heap alloccations are something we want to avoid).
__Best Practice:__ Probably don't ue `std::any`. "If you need to store multiple data types in a single variable, use `std::variant` because it's type-safe and it __wont'__ perform dynamic memory allocation. If you actually _need_ a variable that can store _any_ type of data, probably rethink you're program design."
__Best Practice:__ "Use std::any where in the past you would have used `void*` or `shared_ptr<void>` (which solves tje problem of lifetime management that `void*` has). Which is to say, ideally, almost nowhere." - [SO](https://stackoverflow.com/questions/52715219/when-should-i-use-stdany) 
- [Further discussion](https://devblogs.microsoft.com/cppblog/stdany-how-when-and-why/)

## Move Semantics

### Video #85: l-values and r-values in C++
- (and also l-value and r-values references).
- Often (but not always) an l-value is on the left of the `=` sign and an r-value is on the right of the `=` sign. For example, in `int i = 10`, `i` is an l-value and `10` is an r-value.
- An l-value has a location in memory, and an r-value is simply a _temporary value_ that has no memory allocated to it. An r-value can be a literal, like `10` or it can be the return value of a function. In all cases, we cannot assign another r-value to an r-value.
- You cannot create an l-value reference, e.g. `int&` from an r-value. You can only create an l-value reference from an existing l-value.
- A special rule (related to `const`): You can create a `const` l-value reference from an r-value, e.g. `const int& val = 10;`. This allows us to pass either an l-value or an r-value to a function like:
```
void set_value(const int& value) {
   // do something with value
}

int main() {
   // Create an l-value (i)
   int i = 10;
   
   // Call set_value with an l-value
   set_value(i);

   // Call set_value with an r-value (only possible because set_value takes a
   // const l-value reference)
   set_value(10);
}
```
- Let's look at one more example where `first` and `last` are l-values, but `first + last` is an r-value because it is a temporary object that gets created and then assigned to the l-value `full`.
```
void print_name(const std::string& name) {
   std::cout << name << std::endl;
}

std::string first = "Yan";
std::string last = "Chernikov";

// Assign the r-value "first + last" to the l-value "full".
std::string full = first + last;
print_name(full);

// Only works if print_name accepts a const l-value reference.
print_name(first + last);
```
- Note that a function that accepts both l-values and r-values MUST be written to accept a `const` l-value reference. This is why you'll see a lot of const references being used in C++.
- Do we have a way to write a function that only accepts temporary objects (r-values)? Yes! We need to use something called an _r-value reference_. We can modify the code above such that `print_name` accepts an r-value reference.
```
void print_name(std::string&& name) {
   std::cout << name << std::endl;
}

// The line below will throw the error "An rvalue reference cannot be bound to an lvalue."
print_name(full);
```
- Being able to distinguish an r-value from an l-value is important in the context of _move semantics_ and optimization. If we know that we are dealing with a temporary object (an r-value reference), then we don't have to worry about things like making sure we keep it alive, etc.

### Video #89: Move Semantics in C++
- C++11 introduced _r-value references_ which are necessary for implementing _move semantics_.
- Consider the case where we need to create an object and then pass it to some function that will take ownership of that object. Prior to C++11, this would require us to create a "throw away" object in the current stack frame and then copy that object to the fuction that's receiving it. This creates unnecessary copying and modern C++ should allow us to avoid unnecessary copies.
- So how do we _move_ an object rather than copying it?
   - We must implement a _move constructor_ for the class that we wish to support moving.
   - We need to use `std::move` to invoke that class's move constructor.
   - See `app/move_semantics.cpp` and the `String` class in `typed.h` for an implementation of a _move constroctor_ and use of `std::move`.

### Video #90: `std::move` and the Move Assigment Operator in C++
- The _move constructor_, `Type(Type&& other)` is invoked when constructing a new object and passing it as an r-value reference.
- The _move assignment operator_ is invoked when we want to _move_ an existing object (an x-value near the end of its lifetime?) into another existing object.
   - If we define a _move constructor_ for our class, we _should_ also define the _move assignment operator_. This is referred to as the _Rule of Fifths_. More on this later.
- `std::move` is used in place of `(Type&&)source` to cast an l-value to an r-value (actually an x-value) and deduces the moved-from type at compile-time rather than requiring the user to cast the l-value to an r-value manually, i.e. `(Type&&)`.

## TODO: Workflow & Debugging
Add a section that groups together videos about workflow and debugging.

### Video #49: Using Libraries in C++
- The ethos: If you download my repo from github, that repo should contain everything you need for it to compile and run.
- This video: Learning to link against binaries
- TODO: Didn't finish this video.

### Video #50: Using Dynamic Libraries in C++
- TODO:

### Video #51: Making and Working with Libraries in C++
- TODO:

### Video #70: Conditional and Action Breakpoints in C++
- TODO:

### Video #72: Precompiled Headers in C++
- TODO:

### Video #75: Structured Bindings in C++
- TODO:

### Video #86: Continuous Integration in C++
- TODO:

### Video #87: Static Analysis in C++
- How do we write _better_ code, i.e. code that produces fewer bugs.
- How do we use a _static analyzer_ to improve our code?
- TODO: Finish this video.

## Writing Our Own Data Structures

### Video #91: ARRAY - Making Data Structures in C++
- Finally time to take what we've learned and write out own _data structures_, e.g. arrays, lists, sets, maps, trees, etc. The STL implements most of these data structures for us, but we can learn a lot by trying to implement our own (and maybe even make them fast/ more efficient than the STL data structures).
- In this video, we'll be implementing our own version of `std::array` - a fixed-size, stack-allocated array data structure in C++.
- Recall some differences between `std::array` and `std::vector`:
   - `std::vector` always allocates on the heap and can be dynamically resized, whereas a fixed-size `std::array` allocates its memory on the stack.
   - __Best Practice:__ If you don't need heap allocations, don't use them because they'll just slow things down.
   - `std::vector` can be dynamically allocated, i.e. its size does not have to be determined at compile time, but a `std::array` must define its size at compile-time:
   ```
   // This is just fine
   size_t size = get_size();
   int* heap_arr = new int[size];

   // This throws an error: "Expression must have a constant value."
   int array[size];

   // However, we can use the size of an array to set another array's size
   std::array arr1<int, 10>;
   std::array arr1<float, arr1.size()>;
   ```
- See `include/array.h` and `app/custom_array.cpp` for implementation and use of our custon `Array` class.

### Video #92: VECTOR/DYNAMIC ARRAY - Making Data Structures in C++
- STL's `std::vector` has the following important characteristics:
   - `std::vector` is a re-sizeable array.
   - `std::vector` is heap-allocated (as opposed to `std::array` which is stack-allocated and fixed in size at compile-time).
- What do we need to implement our own vector (dynamic array) class?
   - A pointer to the beginning of a block of heap-allocated memory.
   - The ability to resize our vector when we run out of room to _push back_ a new element. This requires allocating a new block of memory on the heap, copying over the contents of the current vector, and then freeing the memory that was copied from.
- Resizing strategies:
   - Maybe revisit Video #47: Optimizing the Usage of `std::vector`.
   - Instead of copying, we can _move_ the contents of the old vector into the newly resized vector.
   - Note that in more _sophisticated_ dynamic array (vector) implementations, you have the option of specifying a _custom allocator_ that may not necesarily hit the heap each time it needs to resize. This is beyond the scope of this video, but it can be really useful if you're writing a custom piece of software.
- Two options for adding elements to our Vector:
   - `push_back`: Used to add an element to the Vector container by either copying or moving. Moving should be preferred.
   - `emplace_back`: Rather that constructing an instance of the element in the stack frame of the calling function and then _moving_ it into our `Vector` data storage, instead we construct the new element _in place_, i.e. in the memory that we've already allocated for it in `Vector::data_` by simply taking the arguments that we'll pass to the constructor the element type.
      - __Best Practice:__ Prefer _placement_ `new` for _truly_ constructing objects _in place_.
- __Operator new and Operator delete:__ (`::operator new` and `::operator delete`)
   - "A lot of care needs to be taken when you manually call the destructor of the objects in your container" - Cherno.
   - We do this for both `Vector::pop_back` and `Vector::clear`. For a type that doesn't perform any heap allocation, like the `Vec3` class, we won't really run into any issues calling `~Vec3` manually, but as soon as type that your container supports does do some sort of heap allocation, you can very quickly run into issues.
   - "When you write `p = new T[N]`, the compiler generates code that calls `operator new[]` to allocate enough memory for `N` objects of type `T` plus whatever book-keeping information it needs. When you subsequently call `delete[] p`, the compiler calls the destructor for each of the `N` elements in the array that `p` points to, and then calls `operator delete[]` to release the memory that it got from `operator new[]`." - [SO](https://stackoverflow.com/questions/50069257/why-does-operator-new-allocate-memory-for-the-size-of-the-array)

### Video #94: Writing an Iterator in C++
- We'll be adding an iterator to our custom vector class (from video #92).
- An aside: How do we actually get better as a c++ developer?
   - More focus/emphasis on reading and writing real-world code rather than just focusing on textbooks and tutorials.
   - Eventually you'll get to the point where you'll only continue to learn and get better by looking at and working with an existing codebase.
   For example, the `std::vector` template class implements an iterator. So if we want to implement an iterator for our own custom class, we _should_ be looking at the STL for guidance and using it as an example.

### Video #95: How to __Really__ Learn C++
- What should I do next in my C++ learning journey? A simple answer: _open source projects_.