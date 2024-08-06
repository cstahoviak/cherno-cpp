# C++ Quiz
Questions from [cppquiz.org](https://cppquiz.org/).

## C++ Training
The following are questions that I got wrong along with the correct answer and an explanation.

### 109. Lambdas & and `std::function`
According to the C++17 standard, what is the output of this program?
Difficult: 3 (red)
```
#include <functional>
#include <iostream>

template <typename T>
void call_with(std::function<void(T)> f, T val) {
    f(val);
}

int main() {
    auto print = [] (int x) { std::cout << x; };
    call_with(print, 42);
}
```
__My Answer__: Incorrect.\
__Answer__: Compilation error. In C++, al lamda's type is not `std::function<void(T)>`, but something unspecified which can be assigned to a `std::function`.

### 293. `int argc` and `char* argv[]`
- Contrary to common sense beleif about out-of-bounds array element access, `argv[argc] == 0`.

### 35. Overloaded Initialization
- Note that the following two lines are __not__ the same.
    ```
    std::vector<int> v1(1, 2);
    std::vector<int> v2{1, 2};
    ```
- The first line invokes the `std::vector(size_type n, const T& value)` constructor and constructs a vector with `n` copies of `value`, i.e. `v1` contains one `2`.
- The second line uses _braced initialization_ construction via an _initializer list_ and results in a `std::vector` of length 2 with elements `1` and `2`.

### `decltype`
- An object whose type is declared as `decltype(e)` will have the type of the entity named by e.
- In the following code snippet, `b` will be and `int`.
    ```
    int a = 0;
    decltype(a) b = a;
    ```





