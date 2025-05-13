// alarm_tests.cpp
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
  ASSERT_EQ(std::string_view{"invalid"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, string_advisory) {
  Alarm a{Alarm::Type::advisory};
  ASSERT_EQ(std::string_view{"advisory"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, string_caution) {
  Alarm a{Alarm::Type::caution};
  ASSERT_EQ(std::string_view{"caution"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, string_warning) {
  Alarm a{Alarm::Type::warning};
  ASSERT_EQ(std::string_view{"warning"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, ostream_invalid) {
  Alarm a{};
  ss << a;
  ASSERT_EQ(std::string_view{"invalid"}, ss.str());
}

TEST_F(AlarmTest, ostream_advisory) {
  Alarm a{Alarm::Type::advisory};
  ss << a;
  ASSERT_EQ(std::string_view{"advisory"}, ss.str());
}

TEST_F(AlarmTest, ostream_caution) {
  Alarm a{Alarm::Type::caution};
  ss << a;
  ASSERT_EQ(std::string_view{"caution"}, ss.str());
}

TEST_F(AlarmTest, ostream_warning) {
  Alarm a{Alarm::Type::warning};
  ss << a;
  ASSERT_EQ(std::string_view{"warning"}, ss.str());
}

TEST_F(AlarmTest, custom_message_invalid) {
  Alarm a{Alarm::Type::invalid, "Custom invalid message"};
  ASSERT_EQ(Alarm::Type::invalid, a.type());
  ASSERT_EQ(std::string_view{"invalid : Custom invalid message"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, custom_message_advisory) {
  Alarm a{Alarm::Type::advisory, "Custom advisory message"};
  ASSERT_EQ(Alarm::Type::advisory, a.type());
  ASSERT_EQ(std::string_view{"advisory : Custom advisory message"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, custom_message_caution) {
  Alarm a{Alarm::Type::caution, "Custom caution message"};
  ASSERT_EQ(Alarm::Type::caution, a.type());
  ASSERT_EQ(std::string_view{"caution : Custom caution message"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, custom_message_warning) {
  Alarm a{Alarm::Type::warning, "Custom warning message"};
  ASSERT_EQ(Alarm::Type::warning, a.type());
  ASSERT_EQ(std::string_view{"warning : Custom warning message"}, std::string_view{a.to_string()});
}

TEST_F(AlarmTest, ostream_custom_message_invalid) {
  Alarm a{Alarm::Type::invalid, "Custom invalid message"};
  ss << a;
  ASSERT_EQ(std::string_view{"invalid : Custom invalid message"}, ss.str());
}

TEST_F(AlarmTest, ostream_custom_message_advisory) {
  Alarm a{Alarm::Type::advisory, "Custom advisory message"};
  ss << a;
  ASSERT_EQ(std::string_view{"advisory : Custom advisory message"}, ss.str());
}

TEST_F(AlarmTest, ostream_custom_message_caution) {
  Alarm a{Alarm::Type::caution, "Custom caution message"};
  ss << a;
  ASSERT_EQ(std::string_view{"caution : Custom caution message"}, ss.str());
}

TEST_F(AlarmTest, ostream_custom_message_warning) {
  Alarm a{Alarm::Type::warning, "Custom warning message"};
  ss << a;
  ASSERT_EQ(std::string_view{"warning : Custom warning message"}, ss.str());
}
