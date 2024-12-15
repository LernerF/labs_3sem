# Минимальная версия CMake
cmake_minimum_required(VERSION 3.10)

# Название проекта
project(LAB6)

# Установка стандартов компиляции
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указание директорий с заголовками
include_directories(include)

# Основные исходные файлы
set(SOURCES
    src/main.cpp
    src/SlaveTrader.cpp
)

# Создание основного исполняемого файла
add_executable(LAB6 ${SOURCES})

# Установка флагов компиляции
target_compile_options(LAB6 PRIVATE -Wall -Wextra -pedantic)

# Локальная копия Google Test
add_subdirectory(external/googletest-release-1.14.0 googletest-build)

# Тесты
enable_testing()

# Указание тестовых файлов
set(TEST_SOURCES
    tests/test_main.cpp
    tests/test_factory.cpp
    tests/test_npc.cpp
)

# Создание тестового исполняемого файла
add_executable(LAB6_tests ${TEST_SOURCES})
target_link_libraries(LAB6_tests PRIVATE gtest gtest_main pthread)

# Добавление тестов
add_test(NAME RunTests COMMAND LAB6_tests)