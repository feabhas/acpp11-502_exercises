// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "debug.h"
#include <cstring>
#include <iostream>
#include <utility>

using namespace std;

Alarm::Alarm() {
  TRACE("Alarm default ctor");
}

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
  TRACE("Alarm non-default ctor");
}

Alarm::Alarm(Type alarm_init, const char* str) : value{alarm_init} {
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

Alarm::Alarm(Alarm const& rhs) : Alarm{rhs.value, rhs.description} {
  TRACE("Alarm copy ctor");
}

Alarm::Alarm(Alarm&& rhs) noexcept : Alarm{} {
  TRACE("Alarm move ctor");
  swap(*this, rhs);
}

Alarm& Alarm::operator=(Alarm const& rhs) {
  TRACE("Alarm copy op=");
  auto temp{rhs};
  swap(*this, temp);
  return *this;
}

Alarm& Alarm::operator=(Alarm&& rhs) {
  TRACE("Alarm move op=");
  if (this != &rhs) {
    delete[] description;
    value = std::exchange(rhs.value, Type::invalid);
    description = std::exchange(rhs.description, nullptr);
  }
  return *this;
}

void swap(Alarm& lhs, Alarm& rhs) {
  using std::swap;
  swap(lhs.value, rhs.value);
  swap(lhs.description, rhs.description);
}

const char* Alarm::to_string() const {
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

const char* Alarm::what() const {
  return (description != nullptr ? description : "");
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm) {
  os << alarm.to_string() << " - " << alarm.what();
  return os;
}
