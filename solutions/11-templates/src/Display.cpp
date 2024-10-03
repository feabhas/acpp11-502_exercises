// Display.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Display.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>

Display::Display(Pipe& ip) : input{&ip} {}

void Display::execute() {
  assert(input);

  if (auto alarm = input->pull()) {
    if (alarm.value() != nullptr) {
      std::cout << "Display:  " << *(alarm.value()) << '\n';
    }
  }

}

void connect(Display& display, Pipe& pipe) {
  display.input = &pipe;
}
