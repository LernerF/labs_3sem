#ifndef BATTLE_HPP
#define BATTLE_HPP

#include "npc.hpp"
#include <memory>
#include <cstdlib>

void battle(const std::shared_ptr<NPC>& npc1, const std::shared_ptr<NPC>& npc2);

#endif