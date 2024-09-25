// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

int main()
{
  Alarm a1;                                    //
  Alarm a2{};                                  // Value-initialised
  Alarm a3{ Alarm::Type::warning };            // Explicitly initialised
  auto  a4 = make_alarm(Alarm::Type::caution); // factory-function
  print_alarm(a2);
  print_alarm(a3);
  print_alarm(a4);

  // std::cout << static_cast<int>(a1.type()) << '\n';
  // std::cout << a2.to_string() << '\n';
  // std::cout << a1 << '\n';
  // std::cout << a2 << '\n';
  // std::cout << a3 << '\n';
  // std::cout << a4 << '\n';
  a1 = make_alarm(Alarm::Type::advisory); // RVO
  print_alarm(a1);
  std::cout << "\nCompleted OK\n";
}
