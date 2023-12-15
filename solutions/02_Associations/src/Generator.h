// Generator.h
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#pragma once
#ifndef GENERATOR_H
#define GENERATOR_H

class Pipe;

class Generator {
public:
  Generator() = default;
  explicit Generator(Pipe& pipe);
  void execute();

private:
  Pipe* output{};
  friend void connect(Generator& gen, Pipe& pipe);
};

#endif
