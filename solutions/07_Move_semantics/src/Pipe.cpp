// Pipe.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "debug.h"

using namespace std;

// void Pipe::push(Pipe::elem_type const& in)
// {
//   // Copy the elem_type.
//   //
//   TRACE("Pipe::push (copy)");
//   element = in;  // copying Alarm_list
//   empty   = false;
// }

void Pipe::push(Pipe::elem_type&& in) // Rvalue-ref
{
  // Move the elem_type.
  //
  TRACE("Pipe::push (move)");
  element = move(in); // element.op=(rhs{move(in)}); // move-ctor
  // element = in;  // element.op=(rhs{in}); // copy-ctor-> deep copy init
  empty = false;
}

std::optional<Pipe::elem_type> Pipe::pull() {
  TRACE("Pipe::pull");
  if (empty)
    return std::nullopt;
  empty = true;
  return move(element);
}

bool Pipe::is_empty() const {
  return empty;
}
