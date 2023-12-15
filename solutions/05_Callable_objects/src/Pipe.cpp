// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "debug.h"

using namespace std;

void Pipe::push(Pipe::elem_type const& in) {
  // Copy the elem_type.
  TRACE("Pipe::push");
  element = in;
  empty = false;
}

std::optional<Pipe::elem_type> Pipe::pull() {
  TRACE("Pipe::pull");
  if (empty)
    return std::nullopt;
  empty = true;
  return element;
}

bool Pipe::is_empty() const {
  return empty;
}
