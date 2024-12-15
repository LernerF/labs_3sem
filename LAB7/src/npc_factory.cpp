#include "npc_factory.hpp"

std::shared_ptr<NPC> NPCFactory::createNPC(const std::string& name, NPC::Type type, int max_x, int max_y) {
    int x = rand() % (max_x + 1);
    int y = rand() % (max_y + 1);
    return std::make_shared<NPC>(name, type, x, y);
}