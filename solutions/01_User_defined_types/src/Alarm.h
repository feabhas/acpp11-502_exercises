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
  explicit Alarm(Type alarm_init);

  Type type() const;

  const char* to_string() const;

private:
  Type value{Type::invalid};
};

std::ostream& operator<<(std::ostream& os, Alarm const& alarm);

#endif
