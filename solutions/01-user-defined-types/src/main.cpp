// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include <iostream>

int main() {
  Alarm a1;                 //
  Alarm a2{};               // Value-initialised
  Alarm a3{Alarm::warning}; // Explicitly initialised

  std::cout << static_cast<int>(a1.type()) << '\n';
  std::cout << a2.to_string() << '\n';
  std::cout << a3 << '\n';
   
  std::cout << "\nCompleted OK\n";
}
