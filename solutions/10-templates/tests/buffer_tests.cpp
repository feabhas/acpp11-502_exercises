#include "Buffer.h"
#include "Alarm.h"
#include "gtest/gtest.h"

class BufferTest : public ::testing::Test {
protected:
  Buffer<std::unique_ptr<Alarm>, 4> buffer; // Use templated Buffer
};

TEST_F(BufferTest, IsEmptyInitially) {
  ASSERT_TRUE(buffer.is_empty());
}

TEST_F(BufferTest, AddElement) {
  auto alarm = std::make_unique<Alarm>(Alarm::Type::caution);
  ASSERT_TRUE(buffer.add(std::move(alarm)));
  ASSERT_FALSE(buffer.is_empty());
}

TEST_F(BufferTest, GetElement) {
  auto alarm = std::make_unique<Alarm>(Alarm::Type::caution);
  buffer.add(std::move(alarm));
  auto out = buffer.get();
  ASSERT_TRUE(out.has_value());
  ASSERT_EQ(out.value()->type(), Alarm::Type::caution);
  ASSERT_TRUE(buffer.is_empty());
}

TEST_F(BufferTest, AddUntilFull) {
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    ASSERT_TRUE(buffer.add(std::make_unique<Alarm>(static_cast<Alarm::Type>(i % 4))));
  }
  ASSERT_TRUE(buffer.is_full());
  ASSERT_FALSE(buffer.add(std::make_unique<Alarm>(Alarm::Type::warning)));
}

TEST_F(BufferTest, GetFromEmpty) {
  auto out = buffer.get();
  ASSERT_FALSE(out.has_value());
}

TEST_F(BufferTest, AddAndGetMultiple) {
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    ASSERT_TRUE(buffer.add(std::make_unique<Alarm>(static_cast<Alarm::Type>(i % 4))));
  }
  for (std::size_t i = 0; i < buffer.capacity() / 2; ++i) {
    auto out = buffer.get();
    ASSERT_TRUE(out.has_value());
  }
  for (std::size_t i = 0; i < buffer.capacity() / 2; ++i) {
    ASSERT_TRUE(buffer.add(std::make_unique<Alarm>(static_cast<Alarm::Type>(i % 4))));
  }
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    auto out = buffer.get();
    ASSERT_TRUE(out.has_value());
  }
  ASSERT_TRUE(buffer.is_empty());
}