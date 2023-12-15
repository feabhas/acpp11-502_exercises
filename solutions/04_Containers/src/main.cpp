// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>

#include "Display.h"
#include "Generator.h"
#include "Pipe.h"
#include "Pipeline.h"

#include <string>

int main(int argc, char** argv) {
  int run_count = (argc > 1) ? std::stoi(argv[1]) : 1;

  Pipe pipe{};

  Generator generator{pipe};
  Display display{pipe};

  // connect(generator, pipe);
  // connect(display, pipe);

  Pipeline pipeline{};
  pipeline.add(generator);
  pipeline.add(display);

  for (int i{0}; i < run_count; ++i) {
    pipeline.run();
  }

  std::cout << "End of main\n";
}
