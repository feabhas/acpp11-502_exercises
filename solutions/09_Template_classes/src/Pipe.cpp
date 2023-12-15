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
  // Copy the elem_type.
  //
  TRACE("Pipe::push (move)");
  elements.add(move(in));
}

std::optional<Pipe::elem_type> Pipe::pull() {
  TRACE("Pipe::pull");
  // if (is_empty())
  //   return std::nullopt;
  // return elements.get().value_or(elem_type{});
  return elements.get(); // can return std::nullopt from buffer
}

bool Pipe::is_empty() const {
  return elements.is_empty();
}
