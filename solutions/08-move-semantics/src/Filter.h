// Filter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
  virtual void execute() = 0;
  virtual ~Filter()      = default;
};

#endif
