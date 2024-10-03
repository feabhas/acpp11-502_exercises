// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <utility>
#include <iostream>



Alarm::Alarm(Type alarm_init) : value{alarm_init} 
{}

const char* Alarm::to_string() const {
  switch (value) {
  case Type::advisory:
    return "advisory";
  case Type::caution:
    return "caution";
  case Type::warning:
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
