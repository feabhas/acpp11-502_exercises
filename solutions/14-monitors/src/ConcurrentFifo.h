// Buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef CONCURRENTFIFO_H
#define CONCURRENTFIFO_H

#include "Buffer.h"

template<typename T, std::size_t sz = 8>
class ConcurrentFifo : private Buffer<T, sz> {
public:
  using value_type = T;
  ConcurrentFifo() = default;

  template<typename U>
  void add(U&& in);
  auto get() -> value_type;
  bool is_empty() const;

private:
  mutable std::mutex mtx{};
  std::condition_variable has_data{};
  std::condition_variable has_space{};
};

template<typename T, std::size_t sz>
template<typename U>
void ConcurrentFifo<T, sz>::add(U&& in) {
  {
    // std::unique_lock<std::mutex> lock{ mtx };  // C++14
    std::unique_lock lock{mtx};                   // C++17
    while (Buffer<T,sz>::is_full()) {
        has_space.wait(lock);
    }
    Buffer<T,sz>::add(std::move(in));
  }
  has_data.notify_one();
}

template<typename T, std::size_t sz>
auto ConcurrentFifo<T, sz>::get() -> value_type
{
  std::optional<value_type> alarm{};
  {
    // std::unique_lock<std::mutex> lock{ mtx };  // C++14
    std::unique_lock lock{mtx};                   // C++17
    has_data.wait(lock, [this]{ return !Buffer<T,sz>::is_empty(); });
    alarm = std::move(Buffer<T,sz>::get());
  }
  has_space.notify_one();
  return std::move(alarm.value());
}

template<typename T, std::size_t sz>
bool ConcurrentFifo<T, sz>::is_empty() const
{
  return Buffer<T,sz>::is_empty();
}


#endif
