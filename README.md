# cherno-cpp
A repository for working through the Cherno's C++ YouTube series.

Why write in C++? Because we care about things like:
- Memory
- Performace
- Hardware Optimization

If you don't care about these things, don't choose C++!

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
- A note on Constructors: Every constructor in the inheritance hierarchy gets called in the order of base-class -> derived-class.
- Destructors get called in the _reverse_ order!
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

__Video #30: Arrays in C++__
- ...

TODO:
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

__Video #33: `Const` in C++__
- NOTE: This is where I picked up after the interview. I'm taking my time getting through the content now.
- A "promise" that something will not be changed (not actually strictly enforced).
- `const int* ptr`: value at pointer location cannot be changed, i.e. cannot do `*ptr = 100;`, but the pointer can be re-assigned to a new address.
- `int* const ptr`: The pointer cannot be assigned to a new address, but the value at the pointer location can be changed.
- `const int* const ptr`: The pointer cannot be re-assigned to a new address and the value at the pointer location cannot be changed.
- `void MyClass::func() const`: Guarantees that this function will not modify any member variables of `MyClass`, i.e. this function is "read-only".
- Rule of thumb: Mark any methods that are intended to be read-only as `const`, e.g. `void MyClass::func() const`.
- The `mutable` keyword allows `const` methods to modify member variables.

__Video #34: The `Mutable` Keyword in C++__
- Two (very different) use cases: with `const` and with lambdas.
- The `mutable` keyword allows `const` methods to modify member variables.
- lambda (quick definition): a throw-away function that you can assign to a variable.

__Video #35: Member Initializer Lists in C++__
- A way to initialize class member function via the contstructor.
- Member initializer lists are the most memory/time efficient way to construct
an object of a class that consists of non-primitive type members, i.e. members of other class types. For an example of this, see the `member_init.cpp` app that demonstrates how the Entity's Logger is effectively created twice (and thrown away once) when member initialization is used improperly.

__Video #36: Ternary Operators in C++__
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

__Video #37: How to Create/Instantiate Objects in C++__
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

__Video #38: The `new` Keyword in C++__
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

__Video #39: Implicit Conversion and the `explicit` Keyword in C++__
- Implicit Conversion allows C++ to convert between one type and another, so long as only a "single step" conversion exists between those two types.
- `explicit` __disables__ implicit conversion.
- Probably won't find myself using this very often, but good to know it exists and what it does.

__Video #40: Operators and Operator Overloading in C++__
- Operators: `=`, `==`, `<<` (stream insertion), `&`, `&&`, etc.
- `new`, `delete` and `()` are also operators.
- "Operators _are_ functions!"

__Video #41: `this` keyword in C++__
- `this` is a pointer to the current object instance that the member-method belongs to.
- Deferencing (getting the value or object stored at the pointer location) the `this` pointer looks like `this->x_` which is equivalent to `(*this).x_`.
- Can be used to pass the current object (or a pointer to the current object) to another function, e.g. `func(*this)` or `func(this)`.
- Don't ever `delete this`.

__Video #42: Object Lifetime in C++ (Stack/Scope Lifetimes) in C++__
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

__Video #43: Smart Pointers in C++__
- `std::unique_ptr`, `std::shared_ptr`, `std::weak_ptr`
- `new` allocates memory on the heap and `delete` us used to free it.
- Smart pointers are a way to abstract the the `new`/`delete` paradigm away. Some programmers even go so far as to say you should never use the `new` and `delete` keywords.
- Smart pointers are effectively wrappers around raw pointers.
- When you _make_ a smart pointer, it will call `new` and allocate memory, and then (based on which type of smart pointer you use) that memory will automatically be freed when the smart pointer goes out of scope.
- A `std::unique_ptr` is a _scoped pointer_ that cannot be copied.
- A `std::shared_ptr` stores a reference count and the object will only be deleted when that reference count goes to zero. Each time a new `shared_ptr` is made to an existing object, the reference count increases by one.
- A `std::weak_ptr` does not increase the reference count. Having a `weak_ptr` to an object is basically a way of saying "I want to know if this object exists, but I don't want to be the _reason_ that it exists or continues to exist."

__Video #44: Copying and Copy Constructors in C++__
- Copying is expensive and should be avoided if unnecessary.
- The _Copy Constructor_ is supplied by default by C++ and is implemented as a
_shallow copy_. This will create problems for any objects that have heap-allocated member pointers because the pointer itself will be copied. This results in pointer stored by the copied object pointing to the same memory address as the original object. When that memory is freed by the original object, attempting to free that same memory by the copied object will cause hard-to-diagnose errors.
- In order to implement a _deep copy_ of an object, we must rewrtite the Copy Constructor ourselves: `<Type>(const <Type>& other){}`
- __Best Practice__: Prefer passing objects by const reference (`const <type>&`) to prevent unecessary copying.

__Video #45: The Arrow Operator in C++__
- 


__Video #51: Templates in C++__
- 