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
    auto& alarm_ptr = *a_;
    auto original_size = alarm_ptr->size();
    auto it = remove_if(begin(*alarm_ptr), end(*alarm_ptr),
                        [this](auto& alarm) { return alarm.type() == value; });
    alarm_ptr->erase(it, end(*alarm_ptr));

    auto elements_removed = original_size - alarm_ptr->size();
    cout << "Removing " << elements_removed;
    cout << " alarm" << (elements_removed != 1 ? "s" : "");
    cout << '\n';

    output->push(move(alarm_ptr));
    cout << '\n';
  }
}

void connect(Alarm_filter& filter, Pipe& in, Pipe& out) {
  filter.input = &in;
  filter.output = &out;
}
