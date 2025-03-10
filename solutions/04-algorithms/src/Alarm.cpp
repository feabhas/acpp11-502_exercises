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

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
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


Alarm make_alarm(Alarm::Type type)
{
  return Alarm{ type };
}

void print_alarm(Alarm const& alarm)
{
  std::cout << static_cast<int>(alarm.type()) << ':'
            << alarm.to_string()
            << '\n';
}
