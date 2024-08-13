// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm_filter.h"
#include "Display.h"
#include "Generator.h"
#include "Pipe.h"
#include "Pipeline.h"

#include <chrono>
#include <iostream>
#include <string>
#include <thread>

using namespace std;
using namespace chrono_literals;

int main(int argc, char** argv) {
  int const run_count = (argc > 1) ? std::stoi(argv[1]) : 5;

  Pipe pipe1{};
  Pipe pipe2{};

  Generator generator{};
  Display display{};
  Alarm_filter filter{Alarm::advisory};

  connect(generator, pipe1);
  connect(filter, pipe1, pipe2);
  connect(display, pipe2);

  auto run_forever = [](Filter& filter) {
    while (filter.execute())
    { }
  };

  std::thread gen_thread{[run_count, &pipe1](Filter& filter) {
                           for (int i{}; i < run_count; ++i) {
                             filter.execute();
                             this_thread::sleep_for(500ms);
                           }
                           pipe1.push(nullptr);
                         },
                         ref(generator)};

  std::thread filter_thread{run_forever, ref(filter)};
  std::thread display_thread{run_forever, ref(display)};
  
  // Wait for the threads to
  // finish
  //
  gen_thread.join();
  filter_thread.join();
  display_thread.join();
}
