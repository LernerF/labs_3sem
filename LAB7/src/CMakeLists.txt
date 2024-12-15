# Добавляем библиотеку src_lib из исходных файлов
add_library(src_lib npc.cpp npc_factory.cpp map.cpp battle.cpp)

# Указываем заголовочные файлы
target_include_directories(src_lib PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Создаём основной исполняемый файл
add_executable(NPCBattleGame main.cpp)

# Линкуем основную библиотеку
target_link_libraries(NPCBattleGame PRIVATE src_lib)

# Указываем зависимость исполняемого файла от библиотеки
add_dependencies(NPCBattleGame src_lib)