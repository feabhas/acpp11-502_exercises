// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <cstddef>

template<typename T, std::size_t sz = 8>
class Buffer {
public:
  using value_type = T;
  Buffer() = default;

  bool add(value_type const& in);
  bool add(value_type&& in);
  bool get(value_type& out);

  bool                  is_empty() const;
  constexpr std::size_t capacity() const { return sz; }

private:
  using Container = std::array<value_type, sz>;

  Container   elems {};
  typename Container::iterator write_pos{std::begin(elems)};
  typename Container::iterator read_pos{std::begin(elems)};
  std::size_t num_elems {};
};

template<typename T, std::size_t sz>
bool Buffer<T, sz>::add(value_type const& in)
{
  if (num_elems == sz) return false;

  *write_pos = in;
  ++num_elems;
  ++write_pos;
  if (write_pos == std::end(elems)) write_pos = std::begin(elems);

  return true;
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::add(value_type&& in)
{
  if (num_elems == sz) return false;

  *write_pos = std::move(in);
  ++num_elems;
  ++write_pos;
  if (write_pos == std::end(elems)) write_pos = std::begin(elems);

  return true;
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::get(value_type& out)
{
  if (num_elems == 0) return false;

  out = std::move(*read_pos);
  --num_elems;
  ++read_pos;
  if (read_pos == std::end(elems)) read_pos = std::begin(elems);

  return true;
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::is_empty() const
{
  return (num_elems == 0);
}


#endif
