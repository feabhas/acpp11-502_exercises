// Pipe_tests.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipe.h"
#include "gtest/gtest.h"

namespace {
class PipeTest : public ::testing::Test {
protected:
  PipeTest() = default;
  Pipe pipe{};
};
} // namespace

TEST_F(PipeTest, ctor) {
  ASSERT_TRUE(pipe.is_empty());
}

TEST_F(PipeTest, pull_empty) {
  auto rv = pipe.pull();
  ASSERT_EQ(nullptr, rv);
}

TEST_F(PipeTest, push_not_empty) {
  pipe.push(std::make_unique<Alarm>());
  ASSERT_FALSE(pipe.is_empty());
}

TEST_F(PipeTest, push) {
  pipe.push(std::make_unique<Alarm>());
  auto rv = pipe.pull();
  ASSERT_NE(nullptr, rv);
}

TEST_F(PipeTest, push_value) {
  pipe.push(std::make_unique<Alarm>());
  auto rv = pipe.pull();
  ASSERT_EQ(Alarm::Type::invalid, rv->type());
}

TEST_F(PipeTest, push_pull) {
  pipe.push(std::make_unique<Alarm>(Alarm::Type::advisory));
  if (auto rv = pipe.pull()) {
    ASSERT_EQ(Alarm::Type::advisory, rv->type());
  } else {
    FAIL() << "missing object in pipe";
  }
  if (auto rv = pipe.pull()) {
    FAIL() << "unexpected object in pipe";
  }
}
