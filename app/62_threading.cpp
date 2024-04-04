/*
 * Video #62: Threading
 */

#include "utils.h"

#include <iostream>
#include <thread>

using namespace std::literals::chrono_literals;

static bool s_finished = false;

void do_work() {
  // Use the Timer to record how long this function took to execute.
  Timer timer;

  // A function that will do some work...
  while (!s_finished) {
    std::cout << "Working..." << std::endl;
    std::this_thread::sleep_for(1s);
  }
}

int main() {
  // Kick off a worker thread that will call the do_work() fcn.
  std::thread worker(do_work);

  // Once the user pressed 'Enter', set the static "finished" var to true
  std::cin.get();
  s_finished = true;

  // Block execution of the current thread (main) until the worker thread has
  // completed.
  worker.join();
  std::cout << "Finished." << std::endl;

  std::cin.get();
}