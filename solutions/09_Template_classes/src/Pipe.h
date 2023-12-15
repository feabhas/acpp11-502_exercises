// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPE_H
#define PIPE_H

#include "Alarm_list.h"
#include "Buffer.h"
#include <memory>
#include <optional>

class Pipe {
public:
  using elem_type = std::unique_ptr<Alarm_list>;

  // Since unique_ptrs can't be copied
  // we have to disable this method.
  //
  // void      push(elem_type const& in);

  void push(elem_type&& in);
  std::optional<elem_type> pull();
  bool is_empty() const;

private:
  using Container = Buffer<elem_type, 16>;

  Container elements{};
};

#endif
