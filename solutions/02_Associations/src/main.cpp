// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Generator.h"
#include "Pipe.h"

#include <string>

int main(int argc, char** argv) {
  int run_count = (argc > 1) ? std::stoi(argv[1]) : 1;

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
