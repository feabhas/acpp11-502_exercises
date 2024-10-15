// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

#include "Filter.h"
class Pipe;

class Generator : public Filter 
{
public:
  Generator() = default;
  explicit Generator(Pipe& pipe);
  bool execute() override;

private:
  Pipe* output{};
  friend void connect(Generator& gen, Pipe& pipe);
};

#endif
