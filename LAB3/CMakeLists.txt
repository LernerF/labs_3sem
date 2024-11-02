# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(FigureProcessing)

# Установка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавление исходных файлов
set(SOURCE_FILES main.cpp Square.cpp Rectangle.cpp Trapezoid.cpp)

# Основной исполняемый файл программы
add_executable(FigureProcessing ${SOURCE_FILES})

# Подключение Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Настройка тестирования
enable_testing()

# Добавление исполняемого файла для тестов
add_executable(FigureTests test_figures.cpp Square.cpp Rectangle.cpp Trapezoid.cpp)

# Линковка Google Test с тестами
target_link_libraries(FigureTests gtest gtest_main)

# Регистрация тестов
add_test(NAME FigureTests COMMAND FigureTests)