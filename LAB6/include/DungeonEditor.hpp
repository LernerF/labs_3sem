#pragma once
#include "patterns/Factory.hpp"
#include "patterns/Observer.hpp"
#include "patterns/CombatVisitor.hpp"
#include <vector>
#include <iostream>
#include <fstream>

class DungeonEditor {
private:
    std::vector<std::shared_ptr<NPC>> npcs;
    std::vector<std::shared_ptr<Observer>> observers;

public:
    DungeonEditor() {
        observers.push_back(std::make_shared<ConsoleObserver>());
        observers.push_back(std::make_shared<FileObserver>("log.txt"));
    }

    void addNPC(const std::string& type, const std::string& name, int x, int y) {
        npcs.push_back(NPCFactory::createNPC(type, name, x, y));
    }

    void printNPCs() const {
        for (const auto& npc : npcs) {
            std::cout << npc->getName() << " (" << npc->getX() << ", " << npc->getY() << ")" << std::endl;
        }
    }

    void combat(int combat_range) {
        CombatVisitor visitor;

        for (size_t i = 0; i < npcs.size(); ++i) {
            for (size_t j = i + 1; j < npcs.size(); ++j) {
                visitor.visit(npcs[i], npcs[j], observers, combat_range);
            }
        }
    }
};