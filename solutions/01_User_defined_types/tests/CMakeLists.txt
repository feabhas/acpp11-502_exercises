find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(AlarmTest alarm_tests.cpp ${CMAKE_SOURCE_DIR}/src/Alarm.cpp)

target_include_directories(AlarmTest PRIVATE
  ${CMAKE_SOURCE_DIR}/src
 )

target_link_libraries(AlarmTest GTest::gtest GTest::gtest_main)

gtest_discover_tests(AlarmTest)