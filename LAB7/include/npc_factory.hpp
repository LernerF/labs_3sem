#ifndef NPC_FACTORY_HPP
#define NPC_FACTORY_HPP

#include "npc.hpp"
#include <memory>
#include <random>

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& name, NPC::Type type, int max_x, int max_y);
};

#endif