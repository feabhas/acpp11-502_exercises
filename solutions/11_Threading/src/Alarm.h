// Alarm.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_H
#define ALARM_H

#include <iosfwd>

class Alarm {
public:
  enum Type { invalid, advisory, caution, warning };

  Alarm();
  ~Alarm();
  Alarm(Type alarm_init);
  Alarm(Type alarm_init, const char* str);

  Alarm(Alarm const& rhs);
  Alarm(Alarm&& rhs) noexcept;
  Alarm& operator=(Alarm rhs);
  friend void swap(Alarm& lhs, Alarm& rhs);

  const char* to_string() const;
  const char* what() const;
  Type type() const;

private:
  Type value{Type::invalid};
  char* description{};
};

std::ostream& operator<<(std::ostream& os, Alarm const& alarm);

#endif
