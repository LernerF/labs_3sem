cmake_minimum_required(VERSION 3.10)
project(LabProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Включаем папку include
include_directories(include)

# Добавляем исполняемый файл программы
add_executable(program
    main.cpp
    src/Rectangle.cpp
    src/Trapezoid.cpp
    src/Rhombus.cpp
    src/Vector.cpp
)

# Подключение Google Test
enable_testing()
add_subdirectory(tests)