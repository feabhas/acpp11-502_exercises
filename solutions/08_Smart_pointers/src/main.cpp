// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm_filter.h"
#include "Display.h"
#include "Generator.h"
#include "Pipe.h"
#include "Pipeline.h"

#include <string>

int main(int argc, char** argv) {
  int run_count = (argc > 1) ? std::stoi(argv[1]) : 1;

  Pipe pipe1{};
  Pipe pipe2{};

  Generator generator{};
  Display display{};
  Alarm_filter filter{Alarm::advisory};

  connect(generator, pipe1);
  connect(filter, pipe1, pipe2);
  connect(display, pipe2);

  Pipeline pipeline{};
  pipeline.add(generator);
  pipeline.add(filter);
  pipeline.add(display);

  for (int i{0}; i < run_count; ++i) {
    pipeline.run();
  }
}
