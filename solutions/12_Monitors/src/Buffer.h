// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef BUFFER_H
#define BUFFER_H

#include <array>
#include <cstddef>
#include <optional>

template <typename T, std::size_t sz>
class Buffer {
public:
  using value_type = T;

  template <typename U>
  bool add(U&& in);
  std::optional<T> get();
  inline bool is_empty() const;
  inline std::size_t size() const;

private:
  using Container = std::array<T, sz>;
  using Iterator = typename Container::iterator;

  Container elems{};
  Iterator write{std::begin(elems)};
  Iterator read{std::begin(elems)};
  std::size_t num_elems{};
};

template <typename T, std::size_t sz>
template <typename U>
bool Buffer<T, sz>::add(U&& in) {
  if (num_elems == sz)
    return false;

  *write = std::forward<U>(in);
  ++num_elems;
  ++write;
  if (write == std::end(elems))
    write = std::begin(elems);

  return true;
}

template <typename T, std::size_t sz>
std::optional<T> Buffer<T, sz>::get() {
  if (num_elems == 0)
    return std::nullopt;

  auto return_val_iter = read;
  --num_elems;
  ++read;
  if (read == std::end(elems))
    read = std::begin(elems);

  return (std::move(*return_val_iter));
}

template <typename T, std::size_t sz>
bool Buffer<T, sz>::is_empty() const {
  return (num_elems == 0);
}

template <typename T, std::size_t sz>
std::size_t Buffer<T, sz>::size() const {
  return num_elems;
}

#endif
