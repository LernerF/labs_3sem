#include <iostream>
#include "DungeonEditor.hpp"

int main() {
    DungeonEditor editor;

    editor.addNPC("Работорговец", "Торгаш1", 100, 100);
    editor.addNPC("Белка", "Белка1", 105, 105);
    editor.addNPC("Странствующий рыцарь", "Рыцарь1", 200, 200);

    std::cout << "Список NPC:" << std::endl;
    editor.printNPCs();

    std::cout << "Начинаем бой!" << std::endl;
    editor.combat(10);

    return 0;
}