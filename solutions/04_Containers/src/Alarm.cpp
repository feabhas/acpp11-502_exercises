// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "debug.h"
#include <iostream>

Alarm::Alarm() {
  TRACE("Alarm default ctor");
}

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
  TRACE("Alarm non-default ctor");
}

Alarm::~Alarm() {
  TRACE("Alarm dtor");
}

const char* Alarm::to_string() const {
  switch (value) {
  case advisory:
    return "advisory";
  case caution:
    return "caution";
  case warning:
    return "warning";
  default:
    return "invalid";
  }
}

Alarm::Type Alarm::type() const {
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm) {
  os << alarm.to_string();
  return os;
}
