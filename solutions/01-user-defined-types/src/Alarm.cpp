// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

static const char* alarm_strings[] = {
  "invalid",
  "advisory",
  "caution",
  "warning"
};

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
  return alarm_strings[value];
}

Alarm::Type Alarm::type() const {
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm) {
  os << alarm.to_string();
  return os;
}
