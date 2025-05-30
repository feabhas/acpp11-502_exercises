// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd
#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <cstddef>
#include <optional>

template<typename T, std::size_t sz = 8>
class Buffer {
public:
  using value_type = T;
  Buffer() = default;

  bool add(value_type const& in);
  bool add(value_type&& in);
  auto get() -> std::optional<value_type>;

  bool is_empty() const;
  bool is_full() const;

  constexpr auto capacity() const -> std::size_t { return sz; }
  
private:
  using Container = std::array<value_type, sz>;

  Container   elems {};
  typename Container::iterator write_pos{std::begin(elems)};
  typename Container::iterator read_pos{std::begin(elems)};
  std::size_t num_elems {};

  void inc_iterator(typename Container::iterator& it){
    ++it;
    if (it == std::end(elems)) it = std::begin(elems);  
  }
};

template<typename T, std::size_t sz>
bool Buffer<T, sz>::add(value_type const& in)
{
  if (num_elems == sz) return false;

  *write_pos = in;
  ++num_elems;
  inc_iterator(write_pos);

  return true;
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::add(value_type&& in)
{
  if (num_elems == sz) return false;

  *write_pos = std::move(in);
  ++num_elems;
  inc_iterator(write_pos);

  return true;
}

template<typename T, std::size_t sz>
auto Buffer<T, sz>::get() -> std::optional<value_type>
{
  if (num_elems == 0) return std::nullopt;

  auto value = std::move(*read_pos);
  --num_elems;
  inc_iterator(read_pos);

  return value;
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::is_empty() const
{
  return (num_elems == 0);
}

template<typename T, std::size_t sz>
bool Buffer<T, sz>::is_full() const
{
  return (num_elems == sz);
}

#endif
