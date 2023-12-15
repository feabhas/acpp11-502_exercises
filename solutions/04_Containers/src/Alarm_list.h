// Alarm_list.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_LIST_H
#define ALARM_LIST_H

#include "Alarm.h"
#include <vector>

class Alarm_list {
public:
  using Container = std::vector<Alarm>;
  using Iterator = Container::iterator;   // std::vector<Alarm>::iterator
  using size_type = Container::size_type; // std::vector<Alarm>::size_type

  void add(Alarm& in_val);
  void emplace(Alarm::Type type);
  size_type size() const;
  Iterator begin();
  Iterator end();

  void reserve(size_type new_size);

private:
  Container alarms{};
};

#endif
