// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "debug.h"
#include <cstring>
#include <iostream>

using namespace std;

Alarm::Alarm() {
  TRACE("Alarm default ctor");
}

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
  TRACE("Alarm non-default ctor");
}

Alarm::Alarm(Type alarm_init, char const* str) : value{alarm_init} {
  TRACE("Alarm non-default ctor with string");

  if (str) {
    description = new char[strlen(str) + 1];
    strcpy(description, str);
  }
}

Alarm::~Alarm() {
  TRACE("Alarm dtor");
  delete[] description;
}

// Alarm a1{Alarm::warning, "the sky is falling it"};
// Alarm a2{a1}; => copy-ctor
// Alarm a2{a1.value, a1.description};
Alarm::Alarm(Alarm const& rhs) : Alarm{rhs.value, rhs.description} {
  TRACE("Alarm copy ctor");
}

// a2 = a1;  a2.operator=(rhs{a1});
Alarm& Alarm::operator=(Alarm rhs) // swap-copy idiom
{
  // rhs is a copy of a1;
  TRACE("Alarm copy op=");
  // swap(a2, rhs);
  swap(*this, rhs);
  // return a2;
  return *this;
}

void swap(Alarm& lhs, Alarm& rhs) {
  using std::swap;
  swap(lhs.value, rhs.value);
  swap(lhs.description, rhs.description);
}

char const* Alarm::to_string() const {
  switch (value) {
  case advisory:
    return "advisory";
  case caution:
    return "caution ";
  case warning:
    return "warning ";
  default:
    return "invalid ";
  }
}

Alarm::Type Alarm::type() const {
  return value;
}

char const* Alarm::what() const {
  return (description != nullptr ? description : "");
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm) {
  os << alarm.to_string() << " - " << alarm.what();
  return os;
}
