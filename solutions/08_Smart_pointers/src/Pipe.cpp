// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "debug.h"

using namespace std;

// Since unique_ptrs can't be copied
// we have to disable this method.
//
// void Pipe::push(Pipe::elem_type const& in)
// {
//   // Copy the elem_type.
//   //
//   TRACE("Pipe::push (copy)");
//   element = in;
//   empty   = false;
// }

void Pipe::push(Pipe::elem_type&& in) {
  // Move the elem_type.
  TRACE("Pipe::push (move)");
  element = move(in);
  empty = false;
}

std::optional<Pipe::elem_type> Pipe::pull() {
  TRACE("Pipe::pull")
  if (empty)
    return std::nullopt;
  empty = true;
  return move(element);
}

bool Pipe::is_empty() const {
  return empty;
}
