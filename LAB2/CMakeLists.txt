cmake_minimum_required(VERSION 3.10)

project(closest_pair)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
  DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)

FetchContent_MakeAvailable(googletest)

add_executable(closest_pair main.cpp)

enable_testing()

add_executable(closest_pair_tests test_main.cpp)

target_link_libraries(closest_pair_tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(closest_pair_tests)
