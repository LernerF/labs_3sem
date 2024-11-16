# Подключаем Google Test
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
include_directories(../include)

# Создаем тестовый исполняемый файл
add_executable(tests
    ../tests/test.cpp
    ../src/Rectangle.cpp
    ../src/Trapezoid.cpp
    ../src/Rhombus.cpp
    ../src/Vector.cpp
)

# Линкуем с Google Test и pthread
target_link_libraries(tests GTest::GTest GTest::Main pthread)

# Добавляем тесты
add_test(NAME RunTests COMMAND tests)