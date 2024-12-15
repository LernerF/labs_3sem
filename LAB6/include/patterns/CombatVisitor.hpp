#pragma once
#include "../NPC/NPC.hpp"
#include "Observer.hpp"
#include <cmath>
#include <vector>

class CombatVisitor {
public:
    void visit(std::shared_ptr<NPC> npc1, std::shared_ptr<NPC> npc2,
               std::vector<std::shared_ptr<Observer>>& observers, int combat_range) {
        int dx = npc1->getX() - npc2->getX();
        int dy = npc1->getY() - npc2->getY();
        double distance = std::sqrt(dx * dx + dy * dy);

        if (distance <= combat_range) {
            std::string result = npc1->fight(npc2);
            for (auto& observer : observers) {
                observer->update(result);
            }
        }
    }
};