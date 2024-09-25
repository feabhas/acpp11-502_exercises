// Pipeline.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipeline.h"
#include "Filter.h"

Pipeline::Pipeline(std::initializer_list<Filter*> list)
{
  for(auto filter: list) {
    add(*filter);
  }
}

bool Pipeline::add(Filter& filter)
{
  if (next == end(filters)) return false;

  *next = &filter;
  ++next;
  return true;
}

void Pipeline::run()
{
  for (auto filter_ptr : filters) {
    if (filter_ptr) { filter_ptr->execute(); }
  }
}
