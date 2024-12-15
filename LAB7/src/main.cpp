#include "map.hpp"
#include "npc_factory.hpp"
#include "battle.hpp"
#include <thread>
#include <chrono>

void moveNPCs(Map& map, int max_x, int max_y, int kill_distance) {
    auto npcs = map.getAliveNPCs();
    while (true) {
        for (auto& npc : npcs) {
            if (npc->isAlive()) {
                int dx = rand() % 21 - 10;
                int dy = rand() % 21 - 10;
                npc->move(dx, dy, max_x, max_y);
            }
        }

        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                if (npcs[i]->isAlive() && npcs[j]->isAlive()) {
                    int dist = std::sqrt(std::pow(npcs[i]->getX() - npcs[j]->getX(), 2) +
                                         std::pow(npcs[i]->getY() - npcs[j]->getY(), 2));
                    if (dist <= kill_distance) {
                        battle(npcs[i], npcs[j]);
                    }
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

int main() {
    Map map;
    const int map_size_x = 100;
    const int map_size_y = 100;
    const int kill_distance = 10;

    for (int i = 0; i < 50; ++i) {
        auto npc = NPCFactory::createNPC("NPC" + std::to_string(i), NPC::Type::TRADER, map_size_x, map_size_y);
        map.addNPC(npc);
    }

    std::thread movement_thread(moveNPCs, std::ref(map), map_size_x, map_size_y, kill_distance);
    std::thread display_thread([&map]() {
        while (true) {
            map.display();
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }
    });

    movement_thread.join();
    display_thread.join();

    return 0;
}