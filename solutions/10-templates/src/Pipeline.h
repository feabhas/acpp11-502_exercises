// Pipeline.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef PIPELINE_H
#define PIPELINE_H

#include <array>

class Filter;  // Interface

class Pipeline {
public:
  Pipeline() = default;
  Pipeline(std::initializer_list<Filter*> list);
  bool add(Filter& filter);
  void run();

private:
  using Container = std::array<Filter*, 4>;
  using Iterator  = Container::iterator;

  Container filters{};
  Iterator  next{ std::begin(filters) };
};

#endif
