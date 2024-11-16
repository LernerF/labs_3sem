cmake_minimum_required(VERSION 3.10)

project(FigureProcessing)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(SOURCE_FILES main.cpp Square.cpp Rectangle.cpp Trapezoid.cpp)

add_executable(FigureProcessing ${SOURCE_FILES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(FigureTests test_figures.cpp Square.cpp Rectangle.cpp Trapezoid.cpp)

target_link_libraries(FigureTests gtest gtest_main)

add_test(NAME FigureTests COMMAND FigureTests)
