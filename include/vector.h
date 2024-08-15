#pragma once

// Include to get 'size_t'
#include <cstddef>
#include <iostream>

/**
 * @brief Video #94: Implementing an iterator for our custom Vector class.
 * 
 * @tparam Vector 
 */
template<typename Vector>
class VectorIterator
{
  public:
    // Follow the STL naming convention and use "ValueType".
    using ValueType = typename Vector::ValueType;
    using PointerType = ValueType*;
    using ReferenceType = ValueType&;

  public:
    VectorIterator(PointerType ptr) : ptr_(ptr) {}

    /**
     * @brief Define the "pre-fix" increment operator. The pointer is already of
     * the correct type, so this increment will increment the correct number of
     * bytes based on the type that our VEctor container stores.
     * 
     * @return VectorIterator& 
     */
    VectorIterator& operator++() {
      ptr_++;
      return *this;
    }

    /**
     * @brief Define the "post-fix" increment operator. This will return a copy
     * of the VectorIterator object because we don't want to modify the current
     * object in-place.
     * 
     * TODO: A little confused still about the internals of this function.
     * Something to revisit in the future.
     * 
     * @return VectorIterator 
     */
    VectorIterator operator++(int) {
      // Make a copy of the VectorIterator
      VectorIterator it = *this;
      // Increment the current VectorIterator by calling the "pre-fix" increment
      ++(*this);
      // Return the copy
      return it;
    }

    /**
     * @brief Define the "pre-fix" decrement operator.
     * 
     * @return VectorIterator& 
     */
    VectorIterator& operator--() {
      ptr_--;
      return *this;
    }

    /**
     * @brief Define the "post-fix" decrement operator.
     * 
     * @return VectorIterator 
     */
    VectorIterator operator--(int) {
      // Make a copy of the VectorIterator
      VectorIterator it = *this;
      // Decrement the current VectorIterator by calling the "pre-fix" increment
      --(*this);
      // Return the copy
      return it;
    }

    /**
     * @brief Define the index operator.
     * 
     * @param index 
     * @return ReferenceType 
     */
    ReferenceType operator[](int index) {
      // These two lines are equivalent.
      // return *(ptr_[index]);
      return *(ptr_ + index);
    }

    /**
     * @brief Define the arrow operator. This will return the current position
     * of the iterator (not the necessarily the beginning).
     * 
     * @return PointerType 
     */
    PointerType operator->() { return ptr_; }

    /**
     * @brief Define the dereference operator. This will return a reference to a
     * ValueType objecter, i.e. a ReferenceType.
     * 
     * @return ReferenceType 
     */
    ReferenceType operator*() { return *ptr_; }

    // Define the comparison operators.
    bool operator==(const VectorIterator& other) const {
      return ptr_ == other.ptr_;
    }

    // The NEQ operator just returns the opposite of operator==
    bool operator!=(const VectorIterator& other) const {
      return !(*this == other);
    }

  private:
    // ptr_ represents the current position of the iterator. There is no need to
    // initialize with 'nullptr' because it's initialized in the VectorIterator
    // constructor.
    PointerType ptr_;
};

/**
 * @brief Video #92: A custom array class that matches the interface of STL's
 * std::array.
 * 
 * @tparam T 
 */
template<typename T>
class Vector
{
  public:
    // (video #94) Follow the STL naming convention and use "ValueType".
    using ValueType = T;
    using Iterator = VectorIterator<Vector<T>>;

  public:
    Vector() {
      // std::cout << "Vector Constructor." << std::endl;
      // To start, allocate enough memory for 2 elements.
      _reallocate(2);
    }

    // TODO: Support construction via an initializer list.

    ~Vector() {
      // 2. Remove each item in the container by manually calling its destructor.
      // NOTE that we need to be careful here not to cause a "double free
      // detected" error. We'll do this by using "versions" of 'new' and 
      // 'delete', "operator new" and "operator delete", that do not call the
      // item's constructor or destructor, respectively.
      clear();

      // 1. The "standard" 'delete' will call the destructor of each item in the
      // data block (I think?)
      // delete[] data_;

      // 2. Use the version of delete, "operator delete", which will not call
      // the element's destructor.
      ::operator delete(data_, capacity_ * sizeof(T));
    }

    // Returns the current size of the vector
    size_t size() const { return size_; }

    /**
     * @brief Pushes back an item by reference.
     * 
     * @param item 
     */
    void push_back(const T& item) {
      std::cout << "pushing back item '" << item << "' by reference." << 
        std::endl;

      // Resize strategy: Grow the vector by half its current size.
      if (size_ >= capacity_) {
        _reallocate(capacity_ + capacity_ / 2);
      }

      data_[size_] = item;
      size_++;
    }

    /**
     * @brief A push_back() function that accepts a temporary object (r-value)
     * and uses std::move to move the object
     * 
     * @param item 
     */
    void push_back(T&& item) {
      std::cout << "pushing back item '" << item << "' by r-value reference" << 
        std::endl;
      // Resize strategy: Grow the vector by half its current size
      if (size_ >= capacity_) {
        _reallocate(capacity_ + capacity_ / 2);
      }

      // 1. Note that even though this function accepts 'item' as an r-value
      // reference, once we're within the scope of this function, 'item' becomes
      // an l-value (pretty odd, right?). So we need to use std::move() to cast
      // the l-value 'item' as an r-value to "move" it into our data_ array.
      // data_[size_] = std::move(item);

      // 2. (from Nikiux133's YouTube comment) See the comment in _reallocate().
      new(&data_[size_]) T(std::move(item));

      // Increment the size of our container.
      size_++;
    }

    // To implement 'emplace_back', we need to use "variadic templates".
    template<typename... Args>
    T& emplace_back_inefficient(Args&&... args) {
      // Resize strategy: Grow the vector by half its current size.
      if (size_ >= capacity_) {
        _reallocate(capacity_ + capacity_ / 2);
      }

      // Forward 'args' to the constructor of T and "unpack" them via '...'.
      // NOTE that as written, constructing the element here (in the stack frame
      // of emplace_back) and then assigning it to data_[size_] is actually
      // NO DIFFERENT than using the version of push_back that takes an r-value
      // reference. See emplace_back for how to handle this correctly.
      data_[size_] = T(std::forward<Args>(args)...);

      // Use the post-increment operator to return the item at data_[size_] and
      // then perform the increment after.
      return data_[size_++];
    }

    /**
     * @brief Uses the "placement new" operator to "truly" construct the
     * element "in place". As opposed to the Vector::emplace_back_innefficient
     * which is really no different than the version of push_back that takes an
     * r-value reference.
     * 
     * @tparam Args 
     * @param args 
     * @return T& 
     */
    template<typename... Args>
    T& emplace_back(Args&&... args) {
      // Resize strategy: Grow the vector by half its current size
      if (size_ >= capacity_) {
        _reallocate(capacity_ + capacity_ / 2);
      }

      // We can "truly" construct the element "in place" by using the
      // "placement new" operator.
      new(&data_[size_]) T(std::forward<Args>(args)...);

      // Use the post-increment operator to return the item at data_[size_] and
      // then perform the increment after.
      return data_[size_++];
    }

    /**
     * @brief Removes the last element from the container.
     */
    void pop_back() {
      if (size_ > 0) {
        size_--;
        // Remove the last element by explicitly calling its destructor. Calling
        // the destructor of the element type ensures that any resources
        // (memory) owned by the deleted element are freed.
        data_[size_].~T();
      }
    }

    /**
     * @brief Erases all elements from the container. After this, size() returns
     * zero.
     */
    void clear() {
      // Could write a while loop that runs until size_ == 0 instead.
      for (size_t idx = 0; idx < size_; idx++) {
        // Remove each element by calling its destructor.
        data_[idx].~T();
      }
      size_ = 0;
    }

    // TODO: Add erase() function.

    // TODO: Add insert() function.

    // (video #94) Support iteration.
    Iterator begin() { return Iterator(data_); }
    Iterator end() { return Iterator(data_ + size_); }

    // Support indexing into our vector (const and non-const versions are
    // effectively a getter and setter, respectively).
    const T& operator[](size_t index) const {
      if (index >= size_) {
        // TODO: assert if in Debug mode.
      }
      return data_[index];
    }
    T& operator[](size_t index) {
      if (index >= size_) {
        // TODO: assert if in Debug mode.
      }
      return data_[index];
    }
    

  private:
    void _reallocate(size_t new_capacity) {
      std::cout << "Vector Container resizing from '" << size_ << 
        "' elements to '" << new_capacity << "' elements." << std::endl;

      // 1a. Allocate a new block of memory. Note that we could chose to use a
      // unique pointer here, but when working with "low-level" data structures,
      // Cherno prefers to use raw pointers instead of smart pointers.
      // T* new_block = new T[new_capacity];

      // NOTE: It is NOT possible to determine the size of a block of memory
      // given a pointer to that memory block.

      // 1b. Use "operator new" to heap-allocate instead of the method above.
      // Why? Because "operator new" does not call the T constructor. Note that 
      // operator new returns void, so we need to cast it to a T*
      // T* new_block = (T*)::operator new(new_capacity * sizeof(T));
      T* new_block = static_cast<T*>(::operator new(new_capacity * sizeof(T)));

      // TODO: For some reason, ::operator new is allocating a 'new_block' of
      // size 8 instead of size 64. Not sure what's going on here. Posted a
      // comment on Cherno's video. We'll see if he responds.
      // Update: Someone responded! I was making a dumb mistake and calling
      // sizeof() on pointer, which (on a 64bit system) will always be 8 bytes!
      size_t size_T = sizeof(T);
      size_t size_old_block = sizeof(data_);
      size_t size_new_block = sizeof(new_block);

      // If we want to downsize our allocation from a larger block to a smaller
      // block, we will only copy elements up to "new_capacity".
      // TODO: Note that supporting downsizing may be better implemented
      // elsewhere (where?), but we'll do it here for now.
      if (new_capacity < size_) {
        size_ = new_capacity;
      }

      // 2. "Copy" (better to move) the existing elements into the new block of
      // memory. Why not use memcpy here? Because we actually want to be hitting
      // the Copy Constructor of each of our elements. If we were only storing
      // primitive types (int, float), we could use memcpy, but for more complex
      // types like classes, we need to ensure that they are copied "correctly",
      // i.e. according to their own implementation of the copy constructor.
      for (size_t idx = 0; idx < size_; idx++) {
        // 2a. Copy data from old block to new block (bad strategy)
        // new_block[idx] = data_[idx];

        // 2b. Using std::move here instead of copying is perfectly safe to do
        // because in the event that the type being moved does not define a move
        // constructor, its copy constructor will be used instead. So this is
        // really saying, "in the best case scenario, use the move constructor,
        // but if it's not defined use the copy constructor as a fallback."
        // new_block[idx] = std::move(data_[idx]);

        // 2c. (from Nikiux133's YouTube comment) You can't use assignment
        // operator here (either move or copy) because new_block[idx] is 
        // uninitialized memory - it is not the object of type T, and by calling
        // operator= (again move or not) you treat it as if it is an object of
        // type T. So instead of that you should use "placement new" again.
        new(&new_block[idx]) T(std::move(data_[idx]));
      }

      // 3a. Delete the old block of memory.
      // delete[] data_;

      // 3b. Manually call the destructor for each item in the "moved from" data
      // block. Note that this was added at the same time as moving to "operator
      // new" and "operator delete" from the standard new/delete. This is the
      // same as calling Clear(), but it does not set t he size_ to zero.
      for (size_t idx = 0; idx < size_; idx++) {
        data_[idx].~T();
      }

      // 3b. Use "operator delete" instead of the method above. Why? Because 
      // "operator delete" does not call the T destructor. We do that manually
      // in the forloop above, so we want to make sure that we don't attempt to
      // free memory that's already been freed.
      ::operator delete(data_, capacity_ * sizeof(T));

      // 4. Update the data block and capacity.
      data_ = new_block;
      capacity_ = new_capacity;
    }

    // Store a pointer to the allocated memory
    T* data_{nullptr};

    // Store the current size of the vector
    size_t size_{0};

    // Store the vector's current "capacity", i.e. the number of elements that
    // we have actually allocated memory for.
    size_t capacity_{0};
};

// Template functions MUST be defined in a header file (I'm pretty sure?). We
// cannot separate a template function's declaration (typically in a .h) from
// its definition (typically in a .cpp). 
template<typename T>
void print_vector(const Vector<T>& vector) {
  std::cout << "-------------------------------------------------" << std::endl;
  for (size_t idx = 0; idx < vector.size(); idx++) {
    std::cout << vector[idx] << std::endl;
  }
  std::cout << "-------------------------------------------------" << std::endl;
}