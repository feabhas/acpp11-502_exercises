// Alarm.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_H
#define ALARM_H

#include <iosfwd>

class Alarm {
public:
  enum class Type { invalid, advisory, caution, warning };

  Alarm() = default;
  explicit Alarm(Type alarm_init);

  // Implictly delete when move semantics are explicity defined
  Alarm(Alarm const&) = delete;
  Alarm& operator=(Alarm const&) = delete;

  Alarm(Alarm&& rhs) noexcept = default;
  Alarm& operator=(Alarm&& rhs)  noexcept = default;
  
  const char* to_string() const;
  Type        type() const;

private:
  Type value{ Type::invalid };
};

std::ostream& operator<<(std::ostream& os, const Alarm& alarm);

void  print_alarm(Alarm const& alarm);
Alarm make_alarm(Alarm::Type type);

#endif
