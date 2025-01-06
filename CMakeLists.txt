cmake_minimum_required(VERSION 3.10)

project(di)

# Enable C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_library(di src/main.cpp)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
add_executable(ditests tests/DependencyContainerTest.cpp
        tests/ditest.cpp)
target_link_libraries(ditests di GTest::GTest GTest::Main)
