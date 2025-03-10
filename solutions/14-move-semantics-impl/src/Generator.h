// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#ifndef GENERATOR_H
#define GENERATOR_H

#include "Filter.h"

class Pipe;

class Generator : public Filter {
public:
  Generator() = default;
  explicit Generator(Pipe& pipe);
  void execute();

private:
  Pipe* output{};
  friend void connect(Generator& gen, Pipe& pipe);
};

#endif
