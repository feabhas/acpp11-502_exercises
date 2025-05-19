// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#ifndef _PIPE_H
#define _PIPE_H

#include <optional>
#include <memory>
#include "Buffer.h"

class Pipe
{
public:
 using value_type = std::unique_ptr<Alarm>;

  bool push(value_type alarm);
  value_type pull();
  bool is_empty() const;

private:
  Buffer buffer{};
};

#endif
