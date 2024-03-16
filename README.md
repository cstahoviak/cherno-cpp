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
- raw pointers, not discussing _smart pointers_ today.
- A pointer is an integer that represents a memory address.
- Being "invalid" is a perfectly acceptable state for a pointer.
- `0`, `NULL` and `nullptr` mean the same thing when it comes to pointers.

__Video #17: References in C++__
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
   - A `static` method of a class does not have access to the object itself, i.e. cannot access the `this` keyword.
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

__Video #46: Dynamic Arrays in C++ (std::vector)__
- Time to get accustomed with the standard template library (STL)!
- `std::vector` is actually a dynamic array (list) - _dynamic_ in the sense that it can be resized, e.g. extended, appended to, etc.
- When you exceed the allocated size of a particular `std::vector` instance, it creates a new array in memory, copies the contents of the original vector into the new vector and deletes the original vector. In practice, this re-allocation can occur quite often and can result in performance losses.
- Dynamic arrays store their memory contiguously (in line, not fragmented in memory). This is optimal for any operation that requires iterating over the vector.
- When this can become non-optimal is when you anticipate that your vector will need to be resized frequently because this will require copying the objects themselves over and over. _Moving_ instead of cpying largely solves this issue, but not entirely because there is still come copying involved.
- __Question:__ Should I be storing pointers to heap-allocated objects in my vectors (lists), or should I store the stack-allocated objects themselves?
- __Answer:__ It depends. The primary consideration is that it is technically more optimal to store the objects themselves in the list because storing the objects themselves requires that the memory allocated for those objects is inline (contiguous). A vector of pointers can be optimal in the case when thart vector may need to be resized frequently.
__Best Practice:__ Prefer passing dymanic arrays by const reference to avoid uncessary copying.
- `std::array` allocates its memeory on the stack, whereas `std::array` allocates its memory on the heap.

__Video #47: Optimizing the use of std::vector in C++__
- We can use `std::vector.reserve(n)` to allocate enough memory for `n` objects _without_ actually wasting time constructing those objects before we're ready to push them onto the vector.
- We can also use `std::vector.emplace_back()` to construct the object being added to the vector _in place_ (at the location in memory allocated by the vector) as opposed to creating it in the local stack frame and then having to copy it to the memory location allocated by the vector as is done by `std::vector.push_back()`.

__Video #48: Local Static in C++__
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

__Video #49: Using Libraries in C++__
- The ethos: If you download my repo from github, that repo should contain everything you need for it to compile and run.
- This video: Learning to link against binaries
- TODO: Didn't finish this video

__Video #50: Using Dynamic Libraries in C++__
- TODO:

__Video #51: Making and Working with Libraries in C++__
- TODO:

__Video #52: How to deal with Multiple Return Values in C++__
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

__Video #53: Templates in C++__
- A template allows us to get the compiler to write code for us based on a set of rules.
- In `template<typename T>` the keywords `typename` and `class` can _almost_ be used interchangeably. But `typename` is preferred.
- At compile-time, a templated function only gets created (and linked) for the particular types that it's actually called within the source code.
- If a templated function is _never_ called in your code, the the compiler never actually creates any versions of the function, and it's possible to have errors in a templated function that can go undetected.
- The STL (Standard _Template_ Library) is a collection of standarized templated classes.
- __Best Practices:__ When to use templates:
   - Logging systems, buffers than need to contain various types.
- __Best Practices:__ When not to use templates:
   - 

__Video #54: Stack vs. Heap Memory in C++__
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

__Video #55: Macros in C++__
- Macros allow us to use the _pre-processor_ to automate, "macro-ize", some aspects of our code.
- All `#` statements are known as _preprocessor directives_. The Preprocessor step comes before compilation.
- Templates v. Macros:
   - Templates get "evaluated" at compile-time.
   - Macros are evaluated in the preprocessor step and strictly consist of "pure text replacement" which comes before compilation.
- Cherno doesn't like overusing macros.
- __TODO:__ Finish adding a command line CMake variable to enable/disable macros in my code.

__Video #56: The `auto` Keyword in C++__
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

__Video #57: Static Arrays (`std::array`) in C++__
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

__Video #58: Function Pointers in C++__
- This video will focus on C-style _raw_ function pointers.
- Function pointers allow us to assign a function to a variable. Allows us to apply _logic_ to functions and pass functions as arguments to other functions.
- Since functions are effectively just a set of instructions stored somewhere within our binary (executable), the start of those instructions will have a memory address. Thus, we can create a function pointer like:
- __Lambdas__ are functions that are _anonymous_ functions that are declared inline that can be useful when you don't want to define a separate function.

__Video #59: Lambdas in C++__
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

__Video #61: Namespaces in C++__
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

__Video #62: Threads in C++__
- Parallelization!
- Use `std::thread` to start some process, e.g. call a function, in a new thread.
- Use `std::thread::join` to wait for a worker thread to complete before resuming execution of the current thread, i.e. the thread that the worker thread was kicked off from.
- See `app/threading.cpp` for an example.

__Video #63: Timing in C++__
- Since C++11, we have `std::chrono` to help us with timing, i.e. understanding how much time has elapsed between various lines of code.
- See `app/threading.cpp` to see how the `Timer` struct is used as a scope-based (lifetime based) timer to function profiling.
- The topic of _benchmarking_ will come later and will be more in depth. Will discuss _instrumentation_, i.e. modifying source code to contain profiling tooling.

__Video #64: Multidimensional Array (2D Arrays) in C++__
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

__Video #65: Sorting in C++__
- `std::sort` is C++'s built-in sorting algorithm.
- See `app/sorting.cpp` for an example using `std::sort`.

__Video #66: Type Punning in C++__
- Even though C++ is a _strongly-typed_ language, _type punning_ is just a fancy way of getting around the type system of C++. 
- Something that C++ is really good at is raw memory operations (memory maipulation), and we can take advantage of that to do some kind of ridiculous operations. See `app/type_punning.cpp` for an example.
- This can get us into trouble most of the time, but it can also be incredibly powerful. For example, type punning is used in Quake's notoriously fast inverse square root function - it converts a float into a long in order to use bit manipulation.

__Video #67: Unions in C++__
- A Union is a bit like a class or struct type, but it can only occupy the memory of one member at a time. In other words, ... (these are kind of confusing).
- "Put differently, A union of multiple members places each member at the same starting address. This greatly saves on memory used, but the downside is that you can only use one member at a time because they all start at the same address. As you can imagine these were enormously helpful in the 90's when memory was limited. They still have use cases today, but you have to be careful because it can feel like you're' working with separate unique variables when in reality you're working with different variables all occupying the same starting address. Unions can tend to trip you up if you're not careful leading to really wacky bugs but they can be a powerful tool if used seldomly and correctly."
- Useful for when:
   - We want to give two different names to the same variable, e.g. it may be useful to think of a three-element vector (x, y, z) as a color (RGB) where x maps to R and so forth.

__Video #68: Virtual Destructors in C++__
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

__Video #69: Casting in in C++__
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

__TODO: Video #70: Conditional and Action Breakpoints in C++__

__Video #71: Safety in Modern C++ and How to Teach It__
- _Safe_ programming aims to prevent things like crashes, memory leaks (forgetting to free heap-allocated memory) and access violations. This video will focus on pointers and heap allocation.
- Why do we care? Because we want to write real-time, performance-critical production C++ code.
- With C++11, _smart pointers_ were introduced to support this goal. In reality, the entire goal of smart pointers is to automate the use of `delete`.
- Note: `shared_ptr` is __not__ thread safe. (I wonder why?)
