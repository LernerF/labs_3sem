#pragma once
#include "../NPC/SlaveTrader.hpp"
#include "../NPC/Squirrel.hpp"
#include "../NPC/WanderingKnight.hpp"
#include <memory>
#include <stdexcept>

class NPCFactory {
public:
    static std::shared_ptr<NPC> createNPC(const std::string& type, const std::string& name, int x, int y) {
        if (type == "Работорговец") {
            return std::make_shared<SlaveTrader>(name, x, y);
        }
        if (type == "Белка") {
            return std::make_shared<Squirrel>(name, x, y);
        }
        if (type == "Странствующий рыцарь") {
            return std::make_shared<WanderingKnight>(name, x, y);
        }
        throw std::invalid_argument("Unknown NPC type: " + type);
    }
};