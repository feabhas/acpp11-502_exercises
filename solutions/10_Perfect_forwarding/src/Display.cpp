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

  cout << "DISPLAY   : ----------------------------------\n";

  if (auto alarms = input->pull()) {
    auto& alarm_ptr = *alarms;       // extract the unqiue_ptr to alarm_list
    for (auto& alarm : *alarm_ptr) { // extract alarms from list
      cout << alarm << '\n';
    }
    cout << '\n';
  }
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
