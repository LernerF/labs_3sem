cmake_minimum_required(VERSION 3.16)
project(LAB7)

# Устанавливаем стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Включаем поддержку тестов
enable_testing()

# Добавляем исходные файлы
add_subdirectory(src)
add_subdirectory(tests)

# Подключение Google Test через FetchContent
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
    DOWNLOAD_EXTRACT_TIMESTAMP true
)
# Подключение Google Test
FetchContent_MakeAvailable(googletest)

# Создание тестового проекта
add_executable(NPCBattleGameTests tests/test_npc.cpp tests/test_map.cpp)
target_link_libraries(NPCBattleGameTests PRIVATE gtest_main src_lib)

# Включение тестов
include(GoogleTest)
gtest_discover_tests(NPCBattleGameTests)