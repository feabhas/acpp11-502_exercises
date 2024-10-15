// AlarmFilter.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include <iostream>
#include "AlarmFilter.h"
#include "Pipe.h"

AlarmFilter::AlarmFilter(Alarm::Type remove_this)
: value{ remove_this }
{ }

AlarmFilter::AlarmFilter(Alarm::Type remove_this, Pipe& in, Pipe& out)
: value{ remove_this }, input{ &in }, output{ &out }
{ }

bool AlarmFilter::execute()
{
  if (auto alarm = input->pull()) {
    if (alarm->type() == Alarm::Type::invalid) {
      // shutdown
      output->push(std::move(alarm));
      return false;
    }
    if (alarm->type() != this->value) {
      output->push(std::move(alarm));
    }
    else {
      std::cout << "Filter:   " << alarm->to_string() << " removed\n";
    }
  }
  return true;
}

void connect(AlarmFilter& filter, Pipe& in, Pipe& out)
{
  filter.input  = &in;
  filter.output = &out;
}
