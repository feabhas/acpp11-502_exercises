// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include "Alarm_list.h"
#include "Monitor_buffer.h"
#include "debug.h"
#include <memory>
#include <utility>

class Pipe {
public:
  using elem_type = std::unique_ptr<Alarm_list>;

  template <typename T>
  void push(T&& in);

  elem_type pull();
  bool is_empty() const;

private:
  using Container = Monitor_buffer<elem_type, 16>;

  Container elements{};
};

template <typename T>
void Pipe::push(T&& in) {
  TRACE("Pipe::push (forward)");
  elements.add(std::forward<T>(in));
}

#endif
