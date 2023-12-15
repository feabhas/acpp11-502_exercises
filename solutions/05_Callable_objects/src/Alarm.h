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

  Alarm(Alarm const& rhs);
  Alarm& operator=(Alarm const& rhs);

  const char* to_string() const;
  Type type() const;

private:
  Type value{Type::invalid};
};

std::ostream& operator<<(std::ostream& os, Alarm const& alarm);

#endif
