#ifndef MAP_HPP
#define MAP_HPP

#include "npc.hpp"
#include <vector>
#include <mutex>
#include <memory>
#include <iostream>

class Map {
public:
    void addNPC(const std::shared_ptr<NPC>& npc);
    void display() const;
    std::vector<std::shared_ptr<NPC>> getAliveNPCs() const;

private:
    std::vector<std::shared_ptr<NPC>> npcs;
    mutable std::mutex map_mutex;
};

#endif