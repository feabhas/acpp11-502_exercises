// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

int main() {
  Alarm a1;                                    // Default-initialised
  Alarm a2{};                                  // Value-initialised
  Alarm a3{ Alarm::Type::warning };            // Explicitly initialised
  auto  a4 = make_alarm(Alarm::Type::caution); // factory-function

  print_alarm(a1);
  print_alarm(a2);
  print_alarm(a3);
  print_alarm(a4);

  a1 = make_alarm(Alarm::Type::advisory); // RVO
  print_alarm(a1);
  std::cout << "\nCompleted OK\n";
}
