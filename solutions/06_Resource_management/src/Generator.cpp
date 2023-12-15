// Generator.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Generator.h"
#include "Pipe.h"
#include <cassert>
#include <iostream>
#include <random>
#include <array>

using namespace std;

namespace {

std::default_random_engine gen{};

std::uniform_int_distribution random_alarm_type{
    static_cast<int>(Alarm::Type::advisory),
    static_cast<int>(Alarm::Type::warning)
};

auto random_alarm() {
  return (static_cast<Alarm::Type>(random_alarm_type(gen)));
}

constexpr int max_list_size{10};
std::uniform_int_distribution num_of_alarms{1, max_list_size};

auto generate_random_alarm_list_size() {
  return num_of_alarms(gen);
}

constexpr std::array<const char*,6> alarm_strings{
  "Panic!",
  "Run away!",
  "Ignore this alarm.",
  "Oooops!",
  "Things are going horribly wrong.",
  "Please fix immediately."
};

std::uniform_int_distribution num_strings{0, static_cast<int>(alarm_strings.size()-1)};

const char* random_string() {
  return (alarm_strings[static_cast<size_t>(num_strings(gen))]);
}
} // namespace

void Generator::execute() {
  assert(output);

  cout << "GENERATOR : ----------------------------------\n";

  Alarm_list alarms{};

  auto num_alarms = generate_random_alarm_list_size();
  cout << "Generating " << num_alarms << " alarm"
       << (num_alarms != 1 ? "s" : "") << '\n';

  alarms.reserve(static_cast<size_t>(num_alarms));

  for (int i{0}; i < num_alarms; ++i) {
    alarms.emplace(random_alarm(), random_string());
  }

  output->push(alarms);

  cout << '\n';
}

void connect(Generator& gen, Pipe& pipe) {
  gen.output = &pipe;
}
