/*
 * Video #101: NULL
 */

#include <chrono>
#include <iostream>
#include <thread>


/**
 * @brief To illustrate the usefulness of "conversion operators", we're going to
 * implement something from the C++ STL - a scoped pointer. A "scoped pointer"
 * is a unique pointer that is confined to a particular scope.
 * 
 * @tparam T 
 */
template<typename T>
class ScopedPointer
{
  public:
    ScopedPointer() = default;
    ScopedPointer(T* ptr) : ptr_(ptr) {}
    ~ScopedPointer() { delete ptr_; }

    T* get() { return ptr_; }
    const T* get() const { return ptr_; }

    // Define a conversion operator for bool()
    operator bool() const { return ptr_ != nullptr; }
  
  private:
    T* ptr_ = nullptr;
};

struct Entity
{
  float x = 0.0f;
  float y = 0.0f;
};

bool process_entity(const ScopedPointer<Entity>& e) {
  // Note that bool(e) won't work with a ScopedPointer reference unless we
  // define a conversion operator for the bool() operator.
  if (e) {
    // If the entity pointer is valid, do the following...
    return true;
  }
  else {
    return false;
  }
}

struct Timer
{
  public:
    using Clock = std::chrono::high_resolution_clock;
    using TimePoint = std::chrono::time_point<Clock>;

    void start() { start_ = Clock::now(); }
    void stop() { stop_ = Clock::now(); }

    double secs() const {
      using namespace std::chrono;
      return duration_cast<seconds>(stop_ - start_).count();
    }

    double msecs() const {
      using namespace std::chrono;
      return duration_cast<microseconds>(stop_ - start_).count();
    }

    // Instead of implementing the member functions secs() and msecs(), we can
    // define a conversion operator for the double() operator. Then we have to
    // make a choice about whether to return seconds or milliseconds.
    // NOTE: However, for the sake of writing code that is self-documenting,
    // introducing this ambiguity between seconds and milliseconds whenever
    // someone attempts to use our timer as a double is not such a great idea.
    operator double() const { return secs(); }

  private:
    TimePoint start_, stop_;
};


int main()
{
  // Using the ScopedPointer class.
  {
    // Create an Enitity on the heap via a "regular"/raw Enitity pointer
    Entity* entity = new Entity();

    // Manage the Entity via a "scoped pointer"
    ScopedPointer<Entity> e = new Entity();

    // Check to see if pointer is valid
    if(entity) {
      std::cout << "Entity is valid!" << std::endl;
    }
  }

  // Using the Timer class.
  {
    // Use the member function Timer::secs() to display the sleep time
    Timer timer;
    timer.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    timer.stop();
    std::cout << "\nSlept for: " << timer.secs() << " seconds." << std::endl;

    // Now that we've defined a conversion operator for double(), we can do
    std::cout << "Slept for: " << double(timer) << " seconds." << std::endl;

    // We can even do math on our timers as if they were doubles
    Timer timer2;
    timer2.start();
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
    timer2.stop();
    double total_time = timer + timer2;
    std::cout << "\ntotal time: " << total_time << " seconds." << std::endl;

  }

}