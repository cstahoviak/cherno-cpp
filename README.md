# cherno-cpp
A repository for working through the Cherno's C++ YouTube series.

__Video #1: Welcome to C++ (What we'll be learning)__
- How C++ actually works
- Memory and pointers
- Memory "arenas", custom allocators, smart pointers, move semantics
- Templates: "If you know how to use templates well they're extremely powerful and will make your life a lot easier."
- Data structures (and how to make them faster than the standard STL data structures)
- Low-level optimization via "compiler-intrinsics" and assembly.

__Video #5: How C++ Works__
- What we want to know: How to we go from source code (.cpp files) to an executable binary?
- Preprocessor statements (# statements, e.g. #include) happen before compilation.
   - `#include` statements pre-pend the contents of another file into your file.
- Every C++ application needs an "entry point", typically this is `main()`
- operators are just functions! Think of operators as functions.
- Header files do not get compiled. The contents of included files get compiled as part of the cpp files that they're included in.
- The Compiler creates an "object file" (.obj) for every cpp file.
- The "Linker" "glues" the object files into an executable.
   - A linker error can happen when a symbol (e.g. function name) that was "promised" to exist (e.g. via forward-declaration) cannot be resolved or found.
   - This error is referred to as an "unresolved external symbol."

__Video #9: Functions in C++__
- Functions prevent code duplication.
- Each time a function is called in C++, the compiler generates a "call instructions"*. A call instruction creates a "stack frame" for thart function, meaning we have to push the function parameters and return address onto the "stack". Additionally, we have to jump to a different part of our binary to execute a function, and then return to where it was called from. All of this is "expensive".
- *: this only happens if the compiler chooses not to "inline" your function.

__Video #10: Header Files__
- Header files are used to store function and/or class __declarations__ (__not__ definitions).
- `#pragma once`: Only include this file once into a single "translation unit". A translation unit is a single cpp file.

__Video #12: Conditions and Branching in C++__
- `if` statements consist of two parts:
   - The evaluartion of the conditional and the branch(es) that can be jumped to (jumping to a different part of memory).
   - "Optimized" code may attempt to avoid branching altogether to prevent jumping around in memory.

__Video #15: Control Flow in C++__
- `continue`, `break`, `return`

__Video #16: Pointers in C++__
- "Possibly the most important episode in the series!"
- raw pointers, not discussing "smart pointers" today.
- A pointer is an integer that represents a memory address.
- Being "invalid" is a perfectly acceptable state for a pointer.
- `0`, `NULL` and `nullptr` mean the same thing when it comes to pointers.

__Video #16: References in C++__
- References are really just an extension of pointers
- References are "pointers in disguise".
- References must "reference" existing variables, whereas pointers can be created as new variables.

__Video #19: Classes vs. Structs in C++__
- Visibility of member variables:
   - struct: `public` by default.
   - class: `private` by default.

__Video #21: `Static` in C++__
- __Context 1__: `static` keyword when used outside of a class or struct.
   - `static` effectively allows you to mark a variable as "private" for a specfic translation unit (cpp file).
   - This prevents any other translation unit (cpp file) from findind that `static` variable in the linking process via the `extern` keyword.
- __Context 2__: `static` keyword when used inside a class or struct.
   - A `static` member variable of a class/struct is the same across all instances of that class/struct, i.e. there will be only __one instance__ of the `static` member variable.
   - `static` method of a class do not have access to the object itself, i.e. cannot access the `this` keyword.
   - static methods (and also variables?) cannot access non-static variables because static methods do not actually have a "class instance".

__Video #23: Enums in C++__
- Enums provide a way to give a name to a value and organize groups of names and values that make sense together.
- `enum` vs. Enum class?

__Video #25: Destructors in C++__
- The destructor applies to both __stack__ and __heap__ allocated objects.
- If you allocate an object via the `new` keyword, when you call `delete` on that object, the destructor will be called.
- When a stack-based object goes out of scope, the desctrutor will be called.
- Why write a destructor?
   - Any manually-allocated memory on the heap needs to be manually cleaned up in the destructor or you will create memory leaks.

__Video #26: Inheritance in C++__
- Polymorphism: Achieved either via function overloading or operator overloading, e.g. you can use the `+` operator to add two ints, two floats or even concatenate two strings.

__Video #27: Virtual Functions in C++__
- Virtual functions allow us to override methods in sub-classes. A method marked as `virtual` in the parent class can be overridden in the child-class.
- Virtual functions implement "dynamic dispatch" via a "v-table". The v-table contains a mapping of all the virtual functions in the base-class to their overridden functions in the child-class.
- Marking a function as virtual tells the compiler to create a v-table for that function.
- If you want to override a function in the child-class, you __must__ mark the correspodning fucntion in the parent-class as `virtual`. 
- The `override` keyword should be used to mark the child-class method to indicate that it is overriding a virtual method of the parent class.
- Virtual functions come at the expense of creating a v-table, but in reality, the performance difference is negligible.

__Video #28: Interfaces in C++ (Pure Virtual Functions)__
- The concept of a "pure virtual function" in a base class allows us to  define a base-class member function that does not have an implementation, thereby forcing sub-classes to implement that function.
- This is similar to an `abstractmethod` in python.
- An "interface class" consists entirely of "pure virtual methods" and cannot actually be instantiated.
- A sub-class of an interface class can __only__ be instantiated if it implements __all__ of the pure virtual methods defined by the parent-class.

__Video #29 Visibility in C++__
- `private`: these member variables and function can (and should) only be accessed by the class itself
- `protected`: these member variables and function can (and should) only be accessed by the class itself and any sub-class.
- `public`: these member variables and function can (and should) only be accessed by any other class of function.

__Video #30 Arrays in C++__
- 

__Video #33 `Const` in C++__
- NOTE: This is where I picked up after the interview. I'm taking my time getting through the content now.
- A "promise" that something will not be changed (not actually strictly enforced).
- `const int* ptr`: value at pointer location cannot be changed, i.e. cannot do `*ptr = 100;`, but the pointer can be re-assigned to a new address.
- `int* const ptr`: The pointer cannot be assigned to a new address, but the value at the pointer location can be changed.
- `const int* const ptr`: The pointer cannot be re-assigned to a new address and the value at the pointer location cannot be changed.
- `void MyClass::func() const`: Guarantees that this function will not modify any member variables of `MyClass`, i.e. this function is "read-only".
- Rule of thumb: Mark any methods that are intended to be read-only as `const`, e.g. `void MyClass::func() const`.
- The `mutable` keyword allows `const` methods to modify member variables.

__Video #34 The `Mutable` Keyword in C++__
- Two (very different) use cases: with `const` and with lambdas.
- The `mutable` keyword allows `const` methods to modify member variables.
- lambda (quick definition): a throw-away function that you can assign to a variable.

__Video #35 Member Initializer Lists in C++__
- A way to initialize class member function via the contstructor.


33. Const
34. Mutable
37. Creating/Instantiating Objects
38. The New Keyword
40. Operators and Operator Overloading
41. This
42. Object Lifetime (Scope)
43. Smart Pointers
44. Copying and Copy Constructors
45. ->
46. Dynamic Arrays (std::vector)
52. Multiple Return Values
53. Templates
54. Stack vs. Heap
56. auto
58. Function pointers
59. Lambdas
61. Namespaces
62. Threads
79. std::async

__Video #43: Smart Pointers in C++__
- `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- `new` allocates memory on the heap and `delete` us used to free it
- Smart pointers are a way to abstract the the `new`/`delete` paradigm away. Some programmers even go so far as to say you should never use the `new` and `delete` keywords.
- Smart pointers are effectively wrappers around raw pointers
- A `std::unique_ptr` cannot be copied.
- A `std::shared_ptr` stores a reference count and the object will only be deleted when that reference count goes to zero. Each time a new `shared_ptr` is made to an existing object, the reference count increases by one.
- A `std::weak_ptr` does not increase the reference count. Having a `weak_ptr` to an object is basically a way of saying "I want to know if this object exists, but I don't want to be the _reason_ that it exists or continues to exist."

__Video #44: Coping and Copy Constructors__
- 

__Video #51: Templates in C++__
- 