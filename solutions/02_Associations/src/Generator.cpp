// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Pipe.h"
#include <cassert>
#include <cstdlib>
#include <iostream>
#include <random>

using namespace std;

namespace
{
  inline Alarm random_alarm() { return static_cast<Alarm::Type>((rand() % 3) + 1); }
} // namespace

void Generator::execute() {
  assert(output);
  cout << "GENERATOR : ----------------------------------\n";

  Alarm alarm{random_alarm()};
  cout << alarm << '\n';
  output->push(alarm);

  cout << endl;
}

Generator::Generator(Pipe& pipe) : output{&pipe} {}

void connect(Generator& gen, Pipe& pipe) {
  gen.output = &pipe;
}
