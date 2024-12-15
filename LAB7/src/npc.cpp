#include "npc.hpp"
#include <algorithm>

NPC::NPC(std::string name, Type type, int x, int y)
    : name(std::move(name)), type(type), x(x), y(y), alive(true) {}

void NPC::move(int dx, int dy, int max_x, int max_y) {
    x = std::clamp(x + dx, 0, max_x);
    y = std::clamp(y + dy, 0, max_y);
}

bool NPC::isAlive() const {
    return alive;
}

void NPC::kill() {
    alive = false;
}

std::string NPC::getName() const {
    return name;
}

NPC::Type NPC::getType() const {
    return type;
}

int NPC::getX() const {
    return x;
}

int NPC::getY() const {
    return y;
}