// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipeline.h"
#include <iostream>
#include <cassert>

static constexpr int run_count {4};

int main()
{
  // Pipe        pipe1{};
  // Pipe        pipe2{};
  // Generator   generator{ pipe1 };
  // AlarmFilter filter{ Alarm::Type::caution, pipe1, pipe2 };
  // Display     display{ pipe2 };

  // Pipeline pipeline {&generator, &filter, &display};
  // for (int i = 0; i < run_count; ++i) {
  //   pipeline.run();
  // }
  std::array<Alarm::Type, 2> alarms {
    Alarm::Type::warning, Alarm::Type::caution
  };
  Buffer buffer;
  for (auto alarm_type: alarms) {
    buffer.add(std::make_unique<Alarm>(alarm_type));
  }
  Buffer copy1 {buffer};
  for (auto alarm_type: alarms) {
    std::unique_ptr<Alarm> alarm{};
    assert(copy1.get(alarm));
    assert(alarm->type() == alarm_type);
  }
  assert(copy1.is_empty());

  Buffer copy2{};
  copy2 = buffer;
  for (auto alarm_type: alarms) {
    std::unique_ptr<Alarm> alarm{};
    assert(copy2.get(alarm));
    assert(alarm->type() == alarm_type);
  }
  assert(copy2.is_empty());

  std::cout << "\nCompleted OK\n";
}

