// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipeline.h"
#include <iostream>

int main(int argc, char** argv) {
  int run_count = (argc > 1) ? std::stoi(argv[1]) : 5;

  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 };
  AlarmFilter filter{ Alarm::Type::advisory, pipe1, pipe2 };
  Display     display{ pipe2 };

  Pipeline  pipeline1{};
  pipeline1.add(generator);
  pipeline1.add(filter);
  pipeline1.add(display);

  for (int i = 0; i < run_count; ++i) {
    pipeline1.run();
  }

  std::cout << '\n';

  Pipeline pipeline2 {&generator, &filter, &display};
  for (int i = 0; i < run_count; ++i) {
    pipeline2.run();
  }

  std::cout << "Completed OK\n";
}

