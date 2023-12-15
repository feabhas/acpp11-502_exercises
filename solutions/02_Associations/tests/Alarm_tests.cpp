// Alarm_tests.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Alarm.h"
#include "gtest/gtest.h"

namespace {
class AlarmTest : public ::testing::Test {
protected:
  AlarmTest() = default;
  std::stringstream ss{};
};
} // namespace

TEST_F(AlarmTest, type_invalid) {
  Alarm a{};
  ASSERT_EQ(Alarm::Type::invalid, a.type());
}

TEST_F(AlarmTest, type_advisory) {
  Alarm a{Alarm::Type::advisory};
  ASSERT_EQ(Alarm::Type::advisory, a.type());
}

TEST_F(AlarmTest, type_caution) {
  Alarm a{Alarm::Type::caution};
  ASSERT_EQ(Alarm::Type::caution, a.type());
}

TEST_F(AlarmTest, type_warning) {
  Alarm a{Alarm::Type::warning};
  ASSERT_EQ(Alarm::Type::warning, a.type());
}

TEST_F(AlarmTest, string_invalid) {
  Alarm a{};
  ASSERT_EQ("invalid", a.to_string());
}

TEST_F(AlarmTest, string_advisory) {
  Alarm a{Alarm::Type::advisory};
  ASSERT_EQ("advisory", a.to_string());
}

TEST_F(AlarmTest, string_caution) {
  Alarm a{Alarm::Type::caution};
  ASSERT_EQ("caution", a.to_string());
}

TEST_F(AlarmTest, string_warning) {
  Alarm a{Alarm::Type::warning};
  ASSERT_EQ("warning", a.to_string());
}

TEST_F(AlarmTest, ostream_invalid) {
  Alarm a{};
  ss << a;
  ASSERT_EQ("invalid", ss.str());
}

TEST_F(AlarmTest, ostream_advisory) {
  Alarm a{Alarm::Type::advisory};
  ss << a;
  ASSERT_EQ("advisory", ss.str());
}

TEST_F(AlarmTest, ostream_caution) {
  Alarm a{Alarm::Type::caution};
  ss << a;
  ASSERT_EQ("caution", ss.str());
}

TEST_F(AlarmTest, ostream_warning) {
  Alarm a{Alarm::Type::warning};
  ss << a;
  ASSERT_EQ("warning", ss.str());
}
