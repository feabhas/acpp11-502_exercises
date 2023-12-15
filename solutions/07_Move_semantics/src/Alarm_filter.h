// Alarm_filter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_FILTER_H
#define ALARM_FILTER_H

#include "Alarm.h"
#include "Filter.h"

class Pipe;

class Alarm_filter : public Filter {
public:
  Alarm_filter(Alarm::Type remove_this);

  void execute() override;

private:
  Alarm::Type value{};

  Pipe* input{};
  Pipe* output{};
  friend void connect(Alarm_filter& filter, Pipe& in, Pipe& out);
};

#endif
