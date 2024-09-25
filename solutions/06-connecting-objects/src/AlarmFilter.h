// AlarmFilter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef ALARM_FILTER_H
#define ALARM_FILTER_H

#include "Alarm.h"

class Pipe;

class AlarmFilter
{
public:
  explicit AlarmFilter(Alarm::Type remove_this);
  explicit AlarmFilter(Alarm::Type remove_this, Pipe& in, Pipe& out);
  void execute();

private:
  Alarm::Type value;

  Pipe* input{};
  Pipe* output{};
  friend void connect(AlarmFilter& filter, Pipe& in, Pipe& out);
};

#endif
