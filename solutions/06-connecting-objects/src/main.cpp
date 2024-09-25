// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipe.h"
#include <string>
#include <iostream>

int main(int argc, char** argv) {
  int run_count = (argc > 1) ? std::stoi(argv[1]) : 5;

  {
    Pipe pipe{};
    // Generator generator{};
    Generator generator{pipe};
    Display display{pipe};

    // connect(generator, pipe);
    // connect(display, pipe);

    for (int i{0}; i < run_count; ++i) {
      generator.execute();
      display.execute();
    }
  }

  std::cout << '\n';

  {
    Pipe pipe1{};
    Pipe pipe2{};
    Generator generator{pipe1};
    AlarmFilter filter{Alarm::Type::advisory, pipe1, pipe2};
    Display display{pipe2};

    for (int i{0}; i < run_count; ++i) {
      generator.execute();
      filter.execute();
      display.execute();
    }
  }

  std::cout << "\nCompleted OK\n";
}
