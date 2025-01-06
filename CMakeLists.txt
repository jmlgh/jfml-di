cmake_minimum_required(VERSION 3.10)

project(DependencyContainer)

# Enable C++17 or later
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the source files
add_library(DependencyContainer src/main.cpp)

add_executable(MainExecutable src/main.cpp)
target_link_libraries(MainExecutable DependencyContainer)

# Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Test executable
add_executable(DependencyContainerTest tests/ditest.cpp)
target_link_libraries(DependencyContainerTest GTest::GTest GTest::Main)

enable_testing()
add_test(NAME DependencyContainerTest COMMAND DependencyContainerTest)