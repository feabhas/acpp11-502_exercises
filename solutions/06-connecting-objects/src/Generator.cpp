// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Pipe.h"
#include <cassert>
#include <cstdlib>
#include <iostream>

namespace
{
  Alarm random_alarm() { 
    return make_alarm(Alarm::Type((rand()%3) + 1)); 
  }
} // namespace

void Generator::execute() {
  assert(output);

  auto alarm = random_alarm();
  std::cout << "Generate: " << alarm << '\n';
  output->push(alarm);
}

Generator::Generator(Pipe& pipe) : output{&pipe} {}

void connect(Generator& gen, Pipe& pipe) {
  gen.output = &pipe;
}
