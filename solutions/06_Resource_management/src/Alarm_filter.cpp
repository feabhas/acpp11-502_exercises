// Alarm_filter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm_filter.h"
#include "Pipe.h"
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;

Alarm_filter::Alarm_filter(Alarm::Type remove_this) : value{remove_this} {}

void Alarm_filter::execute() {
  assert(input);
  assert(output);

  cout << "ALARM FILTER : -------------------------------\n";

  if (auto a_ = input->pull()) {
    auto& alarms = *a_; // if not std::nullopt then create local binding
    std::cout << "Filtering " << alarms.size() << " alarms\n";
    if (auto it =
            remove_if(begin(alarms), end(alarms),
                      [this](auto& alarm) { return alarm.type() == value; });
        it != end(alarms)) {
      auto dist = std::distance(it, end(alarms));
      cout << "Removing " << dist;
      cout << " alarm" << (dist != 1 ? "s" : "");
      cout << '\n';

      alarms.erase(it, end(alarms));
      output->push(alarms);

      cout << '\n';
    }
  }
}

void connect(Alarm_filter& filter, Pipe& in, Pipe& out) {
  filter.input = &in;
  filter.output = &out;
}
