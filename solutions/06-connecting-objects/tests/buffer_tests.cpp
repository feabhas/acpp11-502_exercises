#include "Buffer.h"
#include "gtest/gtest.h"

class BufferTest : public ::testing::Test {
protected:
  Buffer buffer;
};

TEST_F(BufferTest, IsEmptyInitially) {
  ASSERT_TRUE(buffer.is_empty());
}

TEST_F(BufferTest, AddElement) {
  Alarm alarm{Alarm::Type::caution};
  ASSERT_TRUE(buffer.add(alarm));
  ASSERT_FALSE(buffer.is_empty());
}

TEST_F(BufferTest, GetElement) {
  Alarm alarm{Alarm::Type::caution};
  buffer.add(alarm);
  Alarm out;
  ASSERT_TRUE(buffer.get(out));
  ASSERT_EQ(out.type(), Alarm::Type::caution);
  ASSERT_TRUE(buffer.is_empty());
}

TEST_F(BufferTest, AddUntilFull) {
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    ASSERT_TRUE(buffer.add(Alarm{static_cast<Alarm::Type>(i % 4)}));
  }
  ASSERT_TRUE(buffer.is_full());
  ASSERT_FALSE(buffer.add(Alarm{Alarm::Type::warning}));
}

TEST_F(BufferTest, GetFromEmpty) {
  Alarm out;
  ASSERT_FALSE(buffer.get(out));
}

TEST_F(BufferTest, AddAndGetMultiple) {
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    ASSERT_TRUE(buffer.add(Alarm{static_cast<Alarm::Type>(i % 4)}));
  }
  Alarm out;
  for (std::size_t i = 0; i < buffer.capacity()/2; ++i) {
    ASSERT_TRUE(buffer.get(out));
  }  
  for (std::size_t i = 0; i < buffer.capacity()/2; ++i) {
    ASSERT_TRUE(buffer.add(Alarm{static_cast<Alarm::Type>(i % 4)}));
  }
  for (std::size_t i = 0; i < buffer.capacity(); ++i) {
    ASSERT_TRUE(buffer.get(out));
  }  
  ASSERT_TRUE(buffer.is_empty());
}