// main.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "Buffer.h"
#include <cassert>
#include <iostream>

int main()
{
  Alarm a1;                         //
  Alarm a2{};                       // Value-initialised
  Alarm a3{ Alarm::Type::warning }; // Explicitly initialised

  Buffer pipe{};

  { // Test initial condition
    assert(pipe.is_empty());
  }

  { // Test read from empty
    assert(!pipe.get(a1));
  }

  { // Test add one
    assert(pipe.add(a3));
    assert(!pipe.is_empty());
    assert(pipe.get(a1));
    assert(a1.type() == a3.type());
    assert(pipe.is_empty());
  }

  { // Test add to full
    for (std::size_t count = 0; count < pipe.capacity(); ++count) {
      assert(pipe.add(Alarm{ static_cast<Alarm::Type>(count % 3 + 1) }));
    }
    assert(!pipe.add(Alarm{}));
  }
  { // Test wrap-around behaviour
    // Read 2
    for (std::size_t count = 0; count < 2; ++count) {
      assert(pipe.get(a1));
      assert(a1.type() == Alarm::Type(count+1));
    }

    // write to full again
    assert(pipe.add(a3));
    assert(pipe.add(a3));

    // check full
    assert(!pipe.add(a3));

    // read to empty
    for (std::size_t count = 2; count < pipe.capacity(); ++count) {
      assert(pipe.get(a1));
      assert(a1.type() == Alarm::Type(count % 3 + 1));
    }
    for (std::size_t count = 0; count < 2; ++count) {
      assert(pipe.get(a1));
      assert(a1.type() == a3.type());
    }
    assert(pipe.is_empty());
  }

  std::cout << "Completed OK\n";
}
