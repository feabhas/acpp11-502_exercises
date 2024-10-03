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

void AlarmFilter::execute()
{
  if (std::optional<Alarm> alarm = input->pull()) {
    if (alarm->type() != this->value) {
      output->push(std::move(alarm.value()));
    }
    else {
      std::cout << "Filter:   " << alarm->to_string() << " removed\n";
    }
  } 
}

void connect(AlarmFilter& filter, Pipe& in, Pipe& out)
{
  filter.input  = &in;
  filter.output = &out;
}
