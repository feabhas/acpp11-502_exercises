// Pipeline_tests.cpp
// See project README.md for disclaimer and additional information.
// Feabhas Ltd

#include "Pipeline.h"
#include "gmock/gmock.h"
#include "gtest/gtest.h"
using ::testing::NiceMock;
using ::testing::StrictMock;

#include "Filter.h" // Interface

namespace {

class Mock_filter : public Filter {
public:
  MOCK_METHOD(void, execute, ());
};

class PipelineTest : public ::testing::Test {
protected:
  PipelineTest() = default;
  Pipeline pipeline{};
};

} // namespace

TEST_F(PipelineTest, add_one) {
  NiceMock<Mock_filter> filter{};
  auto rv = pipeline.add(filter);
  ASSERT_TRUE(rv);
}

TEST_F(PipelineTest, execute) {
  StrictMock<Mock_filter> filter{};
  EXPECT_CALL(filter, execute());

  pipeline.add(filter);
  pipeline.run();
}

TEST_F(PipelineTest, full_run) {
  StrictMock<Mock_filter> filter1{};
  StrictMock<Mock_filter> filter2{};
  StrictMock<Mock_filter> filter3{};
  StrictMock<Mock_filter> filter4{};

  EXPECT_CALL(filter1, execute());
  EXPECT_CALL(filter2, execute());
  EXPECT_CALL(filter3, execute());
  EXPECT_CALL(filter4, execute());


  pipeline.add(filter1);
  pipeline.add(filter2);
  pipeline.add(filter3);
  auto rv = pipeline.add(filter4);
  ASSERT_TRUE(rv);

  pipeline.run();
}


TEST_F(PipelineTest, add_to_full) {
  NiceMock<Mock_filter> filter{};

  pipeline.add(filter);
  pipeline.add(filter);
  pipeline.add(filter);
  pipeline.add(filter);

  auto rv = pipeline.add(filter);
  ASSERT_FALSE(rv);
}
