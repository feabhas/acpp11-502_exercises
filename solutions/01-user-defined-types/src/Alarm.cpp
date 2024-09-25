// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

Alarm::Alarm() {
  std::clog << "Alarm default ctor " << this << '\n';
}

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
  std::clog << "Alarm non-default ctor " << this << '\n';
}

Alarm::~Alarm() {
  std::clog << "Alarm dtor" << this << '\n';
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
