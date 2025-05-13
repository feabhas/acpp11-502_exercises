find_package(GTest REQUIRED)
include(GoogleTest)

add_executable(AlarmTest alarm_tests.cpp ${CMAKE_SOURCE_DIR}/src/Alarm.cpp)
add_executable(BufferTest buffer_tests.cpp ${CMAKE_SOURCE_DIR}/src/Alarm.cpp)
add_executable(PipeTest pipe_tests.cpp ${CMAKE_SOURCE_DIR}/src/Pipe.cpp ${CMAKE_SOURCE_DIR}/src/Alarm.cpp)

target_include_directories(AlarmTest PRIVATE
  ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(BufferTest PRIVATE
  ${CMAKE_SOURCE_DIR}/src
)

target_include_directories(PipeTest PRIVATE
  ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(AlarmTest GTest::gtest GTest::gtest_main)
target_link_libraries(BufferTest GTest::gtest GTest::gtest_main)
target_link_libraries(PipeTest GTest::gtest GTest::gtest_main)

gtest_discover_tests(AlarmTest)
gtest_discover_tests(BufferTest)
gtest_discover_tests(PipeTest)