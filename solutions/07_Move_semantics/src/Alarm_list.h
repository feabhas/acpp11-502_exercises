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
  using Iterator = Container::iterator;
  using value_type = Container::value_type;
  using size_type = Container::size_type;

  Alarm_list() = default;
  Alarm_list(Alarm_list const&) = delete;
  Alarm_list& operator=(Alarm_list const&) = delete;
  Alarm_list(Alarm_list&& p) =
      default; //: alarms{p.alarms}{ p.clear();}
  Alarm_list& operator=(Alarm_list&&) = default;

  void reserve(size_type num_elements);
  void add(Alarm& in_val);
  void emplace(Alarm::Type type);
  void emplace(Alarm::Type type, const char* str);
  void erase(Iterator const& from, Iterator const& to);
  size_type size() const;
  Iterator begin();
  Iterator end();

private:
  Container alarms{};
};

#endif
