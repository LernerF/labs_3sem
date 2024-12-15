# Добавляем Google Test и основные файлы для тестов
add_library(test_lib STATIC test_npc.cpp test_map.cpp)

# Подключаем исходный код как зависимость
target_include_directories(test_lib PRIVATE ${PROJECT_SOURCE_DIR}/include)
target_link_libraries(test_lib PRIVATE gtest gmock src_lib)