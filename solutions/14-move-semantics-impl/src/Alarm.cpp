// Alarm.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>
#include <array>
#include <utility>

constexpr std::array<std::string_view,4> alarm_strings
{
  "invalid",
  "advisory",
  "caution",
  "warning"
};

Alarm::Alarm(Type alarm_init) : value{alarm_init} {
}

Alarm::Alarm(Type alarm_init, std::string_view msg)
  : value{alarm_init}, message{msg} {
}

Alarm::Alarm(Alarm&& rhs) noexcept : 
value{std::exchange(rhs.value, Type::invalid)}, 
message{std::exchange(rhs.message, std::string{})} 
{
}

Alarm& Alarm::operator=(Alarm&& rhs) noexcept{
  value = std::exchange(rhs.value, Type::invalid);
  message = std::exchange(rhs.message, std::string{});
  return *this;
}

std::string Alarm::to_string() const {
  if(message.empty()) {
    return std::string{alarm_strings.at(value)};
  }
  return std::string{alarm_strings.at(value)} + std::string{" : "} + message;
}

Alarm::Type Alarm::type() const {
  return value;
}

std::ostream& operator<<(std::ostream& os, Alarm const& alarm) {
  os << alarm.to_string();
  return os;
}


Alarm make_alarm(Alarm::Type type, std::string_view msg) {
  return Alarm{ type, msg };
}

void print_alarm(Alarm const& alarm)
{
  std::cout << static_cast<int>(alarm.type()) << ':'
            << alarm.to_string()
            << '\n';
}
