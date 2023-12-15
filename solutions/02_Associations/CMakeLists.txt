cmake_minimum_required(VERSION 3.18 FATAL_ERROR)

# use current directory to set executable filename
get_filename_component(EXE_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
# set(EXE_NAME AC++11-502)
project(${EXE_NAME})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)

## CPM: An Awesome Dependency Manager for C++ with CMake
set(CPM_DOWNLOAD_VERSION 0.27.2) 
set(CPM_DOWNLOAD_LOCATION "${CMAKE_BINARY_DIR}/cmake/CPM_${CPM_DOWNLOAD_VERSION}.cmake")

if(NOT (EXISTS ${CPM_DOWNLOAD_LOCATION}))
    message(STATUS "Downloading CPM.cmake")
    file(DOWNLOAD https://github.com/TheLartians/CPM.cmake/releases/download/v${CPM_DOWNLOAD_VERSION}/CPM.cmake ${CPM_DOWNLOAD_LOCATION})
endif()

include(${CPM_DOWNLOAD_LOCATION})

# logging famework
CPMAddPackage(
    NAME spdlog
    GITHUB_REPOSITORY gabime/spdlog
    VERSION 1.8.2)

if(spdlog_ADDED)	 
    target_include_directories(spdlog INTERFACE ${spdlog_SOURCE_DIR})	 
endif()

# Add clang-tidy
find_program(
    CLANG_TIDY_EXE
    NAMES
        clang-tidy
    DOC "clang-tidy executable location"
)

# if found then run clang-tidy checks
if(CLANG_TIDY_EXE)
#    set(CMAKE_CXX_CLANG_TIDY "clang-tidy;-checks=-*,cppcoreguidelines-*,clang-analyzer-*,modernize-*,-modernize-use-trailing-return-type")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")  # use local .clang-tidy file instead
endif()


# Warnings
if(MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -g -Og)
endif()

# Add debugging option
# option(USE_TRACE "Enter trace mode" OFF)
if (USE_TRACE)
    add_definitions(-DTRACE_ENABLED)
endif()

set(SOURCE_DIR  src)
include_directories(${SOURCE_DIR})
# not good practice but suitable for our projects
aux_source_directory(${SOURCE_DIR} SOURCES)  

set(OUTPUT_DIR  bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${OUTPUT_DIR})

# The main executable
add_executable(${EXE_NAME} ${SOURCES})

# Using C++ <thread>
target_link_libraries(${EXE_NAME} PRIVATE pthread)

if(spdlog_ADDED)	 
    target_link_libraries(${EXE_NAME} PRIVATE spdlog)
endif()

# allow test to generate .log output
enable_testing()
add_subdirectory(tests)
