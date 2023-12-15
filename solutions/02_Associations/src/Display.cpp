// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

using namespace std;

Display::Display(Pipe& ip) : input{&ip} {}

void Display::execute() {
  assert(input);

  cout << "DISPLAY   : ----------------------------------\n";

  if (auto alarm = input->pull()) {
    cout << *alarm << '\n';
  }

  cout << endl;
}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
