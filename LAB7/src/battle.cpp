#include "battle.hpp"

void battle(const std::shared_ptr<NPC>& npc1, const std::shared_ptr<NPC>& npc2) {
    int attack1 = rand() % 6 + 1;
    int defense2 = rand() % 6 + 1;

    if (attack1 > defense2) {
        npc2->kill();
    }

    int attack2 = rand() % 6 + 1;
    int defense1 = rand() % 6 + 1;

    if (attack2 > defense1) {
        npc1->kill();
    }
}