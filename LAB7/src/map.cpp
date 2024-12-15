#include "map.hpp"

void Map::addNPC(const std::shared_ptr<NPC>& npc) {
    std::lock_guard<std::mutex> lock(map_mutex);
    npcs.push_back(npc);
}

void Map::display() const {
    std::lock_guard<std::mutex> lock(map_mutex);
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            std::cout << npc->getName() << " (" << npc->getX() << ", " << npc->getY() << ")\n";
        }
    }
}

std::vector<std::shared_ptr<NPC>> Map::getAliveNPCs() const {
    std::lock_guard<std::mutex> lock(map_mutex);
    std::vector<std::shared_ptr<NPC>> alive;
    for (const auto& npc : npcs) {
        if (npc->isAlive()) {
            alive.push_back(npc);
        }
    }
    return alive;
}