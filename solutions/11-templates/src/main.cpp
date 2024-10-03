// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "Display.h"
#include "Generator.h"
#include "AlarmFilter.h"
#include "Pipeline.h"
#include <iostream>
#include <cassert>

static constexpr int run_count {6};

void test_buffer();

int main()
{
  test_buffer();

  Pipe        pipe1{};
  Pipe        pipe2{};
  Generator   generator{ pipe1 };
  AlarmFilter filter{ Alarm::Type::advisory, pipe1, pipe2 };
  Display     display{ pipe2 };

  Pipeline pipeline {&generator, &filter, &display};
  for (int i = 0; i < run_count; ++i) {
    pipeline.run();
  }

  std::cout << "\nCompleted OK\n";
}

void test_buffer()
{
  auto a1 = std::make_unique<Alarm>(Alarm::Type::caution); 
  auto a2 = std::make_unique<Alarm>(Alarm::Type::advisory);
  auto a3 = std::make_unique<Alarm>(Alarm::Type::warning);

  Buffer<std::unique_ptr<Alarm>> pipe{};

  { // Test initial condition
    assert(pipe.is_empty());
  }

  { // Test read from empty
    assert(!pipe.get());
  }

  { // Test add one
    assert(pipe.add(std::make_unique<Alarm>(*a3)));
    assert(!pipe.is_empty());
    auto alarm = pipe.get();
    assert(alarm);
    assert(alarm.value()->type() == a3->type());
    assert(pipe.is_empty());
  }

  { // Test add to full
    for (std::size_t count = 0; count < pipe.capacity(); ++count) {
      assert(pipe.add(std::make_unique<Alarm>(static_cast<Alarm::Type>(count % 3 + 1))));
    }
    assert(!pipe.add(std::make_unique<Alarm>()));
  }

  { // Test wrap-around behaviour
    // Read 2
    for (std::size_t count = 0; count < 2; ++count) {
      auto alarm = pipe.get();
      assert(alarm);
      assert(alarm.value()->type() == Alarm::Type(count+1));
    }

    // write to full again
    assert(pipe.add(std::make_unique<Alarm>(*a3)));
    assert(pipe.add(std::make_unique<Alarm>(*a3)));

    // check full
    assert(!pipe.add(std::make_unique<Alarm>(*a3)));

    // read to empty
    for (std::size_t count = 2; count < pipe.capacity(); ++count) {
      auto alarm = pipe.get();
      assert(alarm);
      assert(alarm.value()->type() == Alarm::Type(count % 3 + 1));
    }
    for (std::size_t count = 0; count < 2; ++count) {
      auto alarm = pipe.get();
      assert(alarm);
      assert(alarm.value()->type() == a3->type());
    }
    assert(pipe.is_empty());
  }
  std::cout << "Tests passed\n";
}

