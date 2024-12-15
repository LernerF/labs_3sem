#pragma once
#include "NPC.hpp"

// Forward declaration
class Squirrel;
class WanderingKnight;

class SlaveTrader : public NPC {
public:
    SlaveTrader(const std::string& name, int x, int y) : NPC(name, x, y) {}

    std::string fight(std::shared_ptr<NPC> other) override;
};