// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipeline.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

static constexpr int run_count {6};

int main()
{
  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 };
  AlarmFilter filter{ Alarm::Type::advisory, pipe1, pipe2 };
  Display     display{ pipe2 };

  auto run_fixed = [&pipe1](Filter& filter) {
    for (int i{}; i < run_count; ++i) {
      filter.execute();
      // std::this_thread::sleep_for(500ms);
    }
    pipe1.push(nullptr);
  };

  auto run_forever = [](Filter& filter) {
    while (filter.execute())
    { }
  };

  std::thread gen_thread {run_fixed, std::ref(generator)};
  std::thread filter_thread{run_forever, std::ref(filter)};
  std::thread display_thread{run_forever, std::ref(display)};
  
  // Wait for the threads to
  // finish
  //
  gen_thread.join();
  filter_thread.join();
  display_thread.join();
  
  std::cout << "\nCompleted OK\n";
}
