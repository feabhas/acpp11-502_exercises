// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

using namespace std;

void Display::execute() {
  assert(input);

  if (auto alarm_ptr_opt = input->pull()) {
    cout << "DISPLAY   : ----------------------------------\n";
    auto& alarm_ptr = *alarm_ptr_opt;
    for (auto& alarm : *alarm_ptr) {
      cout << alarm << '\n';
    }
    cout << '\n';
  }
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
