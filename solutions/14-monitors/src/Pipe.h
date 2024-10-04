// Pipe.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef _PIPE_H
#define _PIPE_H

#include <optional>
#include <memory>
#include <condition_variable>
#include <mutex>
#include "Buffer.h"
#include "Alarm.h"

class Pipe
{
public:
  using value_type = std::unique_ptr<Alarm>;

  void push(value_type&& alarm);
  auto pull() -> value_type;
  bool is_empty() const;

private:
  using Container = Buffer<value_type, 4>;
  Container buffer{};

  mutable std::mutex mtx{};
  std::condition_variable has_data{};
  std::condition_variable has_space{};
};

#endif
