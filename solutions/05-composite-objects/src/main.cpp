// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>
#include <cassert>
#include "Alarm.h"
#include "Pipe.h"

static constexpr unsigned alarm_count {5};
static std::array<Alarm, alarm_count> alarms {
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::advisory},
  Alarm{Alarm::Type::warning},
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::warning},
};

int main()
{
  Pipe pipe{};
  for (auto const& alarm: alarms) {
    pipe.push(alarm);
  }

  for (size_t i = 0; i < alarms.size(); ++i) {
    auto alarm = pipe.pull();
    assert(alarm);
    assert(alarm->type() == alarms[i].type());
  }
  assert(pipe.is_empty());

  std::cout << "Completed OK" << '\n';
}
