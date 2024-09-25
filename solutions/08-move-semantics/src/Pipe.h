// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef _PIPE_H
#define _PIPE_H

#include <optional>
#include "Buffer.h"

class Pipe
{
public:
  bool push(Alarm&& alarm);
  std::optional<Alarm> pull();
  bool is_empty() const;

private:
  Buffer buffer{};
};

#endif
