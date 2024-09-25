// Filter.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef FILTER_H
#define FILTER_H

class Filter {
public:
  virtual bool execute() = 0;
  virtual ~Filter()      = default;
};

#endif
