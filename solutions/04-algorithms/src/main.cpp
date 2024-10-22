// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <array>
#include <string>
#include <algorithm>
#include <cassert>
#include <iostream>

static constexpr unsigned alarm_count {12};

static std::array<Alarm, alarm_count> alarms {
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::advisory},
  Alarm{Alarm::Type::warning}, // 1
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::advisory},
  Alarm{Alarm::Type::warning}, // 2
  Alarm{Alarm::Type::warning}, // 3
  Alarm{Alarm::Type::caution},
  Alarm{Alarm::Type::advisory},
  Alarm{Alarm::Type::warning}, // 4
};

static constexpr unsigned warning_count {4};

int main() {
  {
    auto count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::warning; }
    );
    assert(count == warning_count);
  }

  {
    auto remove = std::remove_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::warning; }
    );
    
    // fill end of array with invalid objects
    std::fill(remove,  std::end(alarms), Alarm{}); 

    auto count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() == Alarm::Type::warning; }
    );
    assert(count == 0);

    // check we din't remove everything including caution
    count = std::count_if(
      std::begin(alarms), std::end(alarms), 
      [](auto alarm) { return alarm.type() != Alarm::Type::invalid; }
    );
    assert(count == (std::size(alarms) - warning_count));
  }
  std::cout << "Completed OK\n";
}
