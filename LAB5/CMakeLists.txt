cmake_minimum_required(VERSION 3.28)  # Добавляем минимальную версию CMake

# Устанавливаем имя проекта
project(CustomMemoryVector)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Указываем исходные файлы для основной программы
set(SOURCES
    main.cpp
    memory.cpp
)

# Создаём исполняемый файл для основной программы
add_executable(program ${SOURCES})

# Добавляем флаги компилятора для вывода предупреждений (опционально)
if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(program PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Указываем файлы для тестов
set(TEST_SOURCES
    test.cpp
    memory.cpp  # Добавьте сюда memory.cpp, если он используется в тестах
)

# Добавляем исполняемый файл для тестов
add_executable(tests ${TEST_SOURCES})

# Подключаем Google Test
find_package(GTest REQUIRED)
target_link_libraries(tests GTest::GTest GTest::Main)

# Устанавливаем политику для использования GTest
if (COMMAND cmake_policy)
  cmake_policy(SET CMP0012 NEW)  # Политика для аргументов с "ON"
  cmake_policy(SET CMP0003 NEW)  # Политика для библиотек
  cmake_policy(SET CMP0028 NEW)  # Политика для двойных двоеточий в именах
endif()

# Добавляем тесты в проект
enable_testing()
add_test(NAME AllTests COMMAND tests)

find_package(Threads REQUIRED)
target_link_libraries(tests Threads::Threads)
