// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>
#include <random>

namespace
{
  Alarm random_alarm() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dis(1, 3);
    return make_alarm(Alarm::Type(dis(gen)));
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
