find_package(GTest REQUIRED)
include(GoogleTest)

set(units_under_test
  Pipe
  Alarm
)

# set(UUT_SOURCES
#   ${PROJECT_SOURCE_DIR}/src/Pipe.cpp 
#   ${PROJECT_SOURCE_DIR}/src/Alarm.cpp
# )

# add_executable(AlarmTest alarm_tests.cpp ${UUT_SOURCES})
# target_include_directories(AlarmTest PRIVATE
#   ${CMAKE_SOURCE_DIR}/src
#  )
# target_link_libraries(AlarmTest GTest::gtest GTest::gtest_main)
# gtest_discover_tests(AlarmTest)

# add_executable(PipeTest pipe_tests.cpp ${UUT_SOURCES})
# target_include_directories(PipeTest PRIVATE
#   ${CMAKE_SOURCE_DIR}/src
#  )
# target_link_libraries(PipeTest GTest::gtest GTest::gtest_main)
# gtest_discover_tests(PipeTest)

set(UUT_SOURCES)

# Build list of source files required for unit testing
foreach(unit IN LISTS units_under_test)
  set(SOURCES ${PROJECT_SOURCE_DIR}/src/${unit}.cpp)
  if(EXISTS ${SOURCES})
	  list(APPEND UUT_SOURCES ${PROJECT_SOURCE_DIR}/src/${unit}.cpp)
  endif()
endforeach()


macro(add_test_targets test_case)
  set(TEST_SOURCE ${PROJECT_SOURCE_DIR}/tests/${test_case}_tests.cpp)
  if(EXISTS ${TEST_SOURCE})
    add_executable(${test_case}Test ${TEST_SOURCE} ${UUT_SOURCES})
    target_include_directories(${test_case}Test PRIVATE
      ${CMAKE_SOURCE_DIR}/src
    )
    target_link_libraries(${test_case}Test GTest::gtest GTest::gtest_main)
    gtest_discover_tests(${test_case}Test)
  endif()
endmacro()


# create test for each source file
foreach(unit IN LISTS units_under_test)
	message(STATUS "Adding test: ${units}")
	add_test_targets(${unit})
endforeach()