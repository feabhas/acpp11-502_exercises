// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include "Alarm_list.h"
#include <optional>

class Pipe {
public:
  using elem_type = Alarm_list;
  Pipe() = default;

  // void      push(elem_type const& in);
  void push(elem_type&& in);
  std::optional<elem_type> pull();
  bool is_empty() const;

private:
  elem_type element{};
  bool empty{true};
};

#endif
