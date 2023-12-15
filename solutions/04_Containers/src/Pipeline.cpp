// Pipeline.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipeline.h"
#include "Filter.h"

using namespace std;

bool Pipeline::add(Filter& filter) {
  if (next == end(filters))
    return false;

  *next = &filter;
  ++next;
  return true;
}

void Pipeline::run() {
  for (auto& filter_ptr : filters) {
    if (filter_ptr) {
      filter_ptr->execute();
    }
  }
}
