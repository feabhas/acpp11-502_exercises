// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#ifndef BUFFER_H
#define BUFFER_H

#include "Alarm.h"
#include <array>
#include <cstddef>
#include <memory>

class Buffer {
public:
  Buffer()         = default;

  bool add(std::unique_ptr<Alarm> in);
  bool get(std::unique_ptr<Alarm>& out);

  bool is_empty() const;
  bool is_full() const;

  constexpr auto capacity() const -> std::size_t { return sz; }
  
private:
  static constexpr std::size_t sz{ 8 };
  using Container = std::array<std::unique_ptr<Alarm>, sz>;

  Container   elems {};
  Container::iterator write_pos{std::begin(elems)};
  Container::iterator read_pos{std::begin(elems)};
  size_t      num_elems {};
};

#endif
