// Alarm.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd
#ifndef ALARM_H
#define ALARM_H

#include <iosfwd>
#include <string>
#include <string_view>

class Alarm {
public:
  enum Type { invalid, advisory, caution, warning };

  Alarm() = default;
  explicit Alarm(Type alarm_init);
  explicit Alarm(Type alarm_init, std::string_view msg);

  Alarm(Alarm const&) = delete;
  Alarm& operator=(Alarm const&) = delete;
  Alarm(Alarm&&) noexcept;
  Alarm& operator=(Alarm&&) noexcept;

  Type type() const;

  std::string to_string() const;

private:
  Type value{Type::invalid};
  std::string message{};
};

std::ostream& operator<<(std::ostream& os, Alarm const& alarm);

void  print_alarm(Alarm const& alarm);
Alarm make_alarm(Alarm::Type type, std::string_view msg = "");

#endif
