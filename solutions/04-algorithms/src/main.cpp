// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <array>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>

static constexpr unsigned alarm_count {5};
static std::array<Alarm, alarm_count> alarms {
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::advisory},
  Alarm{Alarm::Type::warning},
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::warning},
};

int main() {
  {
    auto count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::warning; }
    );
    assert(count == 2);
  }

  {
    auto remove = std::remove_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::caution; }
    );
    for(auto it = remove; it != std::end(alarms); ++it) {
      *it = Alarm{};
    }

    auto count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::caution; }
    );
    assert(count == 0);

    // check we din't remove everything including caution
    count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() != Alarm::Type::invalid; }
    );
    assert(count == 3);
  }
  std::cout << "Completed OK\n";
}
