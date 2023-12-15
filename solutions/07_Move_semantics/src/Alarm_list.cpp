// Alarm_list.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm_list.h"

void Alarm_list::add(Alarm& in_val) {
  alarms.push_back(in_val);
}

void Alarm_list::emplace(Alarm::Type type) {
  alarms.emplace_back(type);
}

void Alarm_list::emplace(Alarm::Type type, const char* str) {
  alarms.emplace_back(type, str);
}

Alarm_list::size_type Alarm_list::size() const {
  return alarms.size();
}

Alarm_list::Iterator Alarm_list::begin() {
  return alarms.begin();
}

Alarm_list::Iterator Alarm_list::end() {
  return alarms.end();
}

void Alarm_list::erase(Alarm_list::Iterator const& from,
                       Alarm_list::Iterator const& to) {
  alarms.erase(from, to);
}

void Alarm_list::reserve(Alarm_list::size_type num_elements) {
  alarms.reserve(num_elements);
}
