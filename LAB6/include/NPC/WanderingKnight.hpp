#pragma once
#include "NPC.hpp"
#include "SlaveTrader.hpp"
#include "Squirrel.hpp"

class WanderingKnight : public NPC {
public:
    WanderingKnight(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string fight(std::shared_ptr<NPC> other) override {
        if (typeid(*other) == typeid(SlaveTrader)) {
            return name + " (Рыцарь) убивает " + other->getName() + " (Работорговец).";
        }
        if (typeid(*other) == typeid(Squirrel)) {
            return name + " (Рыцарь) убивает " + other->getName() + " (Белка).";
        }
        if (typeid(*other) == typeid(WanderingKnight)) {
            return other->getName() + " (Рыцарь) убивает " + name + " (Рыцарь).";
        }
        return "Неизвестный исход битвы.";
    }
};