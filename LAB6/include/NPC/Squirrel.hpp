#pragma once
#include "NPC.hpp"

class Squirrel : public NPC {
public:
    Squirrel(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string fight(std::shared_ptr<NPC> other) override {
        if (typeid(*other) == typeid(Squirrel)) {
            return name + " (Белка) убивает " + other->getName() + " (Белка).";
        }
        return name + " (Белка) погибает в бою с " + other->getName() + ".";
    }
};