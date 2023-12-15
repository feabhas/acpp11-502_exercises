// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

void Display::execute() {
  assert(input);

  std::cout << "DISPLAY   : ----------------------------------\n";

  if (auto alarms = input->pull()) {
    for (auto& alarm : *alarms) {
      std::cout << alarm << '\n';
    }
    std::cout << '\n';
  }
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
