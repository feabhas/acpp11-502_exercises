// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

using namespace std;

bool Display::execute() {
  assert(input);
  if (input->is_empty())
    return true;

  cout << "DISPLAY   : ----------------------------------\n";

  auto alarm_ptr = input->pull().value();
  if (not alarm_ptr) {
    return false;
  }

  for (auto& alarm : *alarm_ptr) {
    cout << alarm << '\n';
  }

  cout << '\n';
  return true;
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
