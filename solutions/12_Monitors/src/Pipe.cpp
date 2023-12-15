// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "debug.h"

using namespace std;

Pipe::elem_type Pipe::pull() {
  TRACE("Pipe::pull");
  return elements.get();
}

bool Pipe::is_empty() const {
  return elements.is_empty();
}
