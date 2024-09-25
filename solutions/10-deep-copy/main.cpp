// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipeline.h"
#include <iostream>

static constexpr int run_count {4};

int main()
{
  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 };
  AlarmFilter filter{ Alarm::Type::caution, pipe1, pipe2 };
  Display     display{ pipe2 };

  Pipeline pipeline {&generator, &filter, &display};
  for (int i = 0; i < run_count; ++i) {
    pipeline.run();
  }

  std::cout << "\nCompleted OK\n";
}

