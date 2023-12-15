// Monitor_buffer.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef MONITOR_BUFFER_H
#define MONITOR_BUFFER_H

#include "Buffer.h"
#include <condition_variable>
#include <mutex>

template <typename T, std::size_t sz>
class Monitor_buffer : private Buffer<T, sz> {
public:
  template <typename U>
  void add(U&& in);
  T get();
  bool is_empty() const;
  std::size_t size() const;

private:
  using Base = Buffer<T, sz>;

  // mutex must be mutable for
  // use with const member
  // functions
  //
  mutable std::mutex mtx{};
  std::condition_variable has_data{};
  std::condition_variable has_space{};
};

template <typename T, std::size_t sz>
template <typename U>
void Monitor_buffer<T, sz>::add(U&& in) {
  // std::unique_lock<std::mutex> lock{ mtx };  // C++14
  std::unique_lock lock{mtx}; // C++17

  while (Base::size() == sz) {
    has_space.wait(lock);
  }

  Base::add(std::forward<U>(in));
  has_data.notify_one();
}

template <typename T, std::size_t sz>
T Monitor_buffer<T, sz>::get() {
  // std::unique_lock<std::mutex> lock{ mtx };  // C++14
  std::unique_lock lock{mtx}; // C++17

  while (Base::is_empty()) {
    has_data.wait(lock);
  }

  auto out = Base::get().value();
  has_space.notify_one();
  return out;
}

template <typename T, std::size_t sz>
bool Monitor_buffer<T, sz>::is_empty() const {
  // std::lock_guard<std::mutex> lock{ mtx }; // C++14
  std::lock_guard lock{mtx}; // C++17
  return Base::is_empty();
}

template <typename T, std::size_t sz>
std::size_t Monitor_buffer<T, sz>::size() const {
  // std::lock_guard<std::mutex> lock{ mtx }; // C++14
  std::lock_guard lock{mtx}; // C++17
  return Base::size();
}

#endif
