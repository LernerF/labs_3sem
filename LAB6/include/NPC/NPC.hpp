#pragma once
#include <string>
#include <memory>

class NPC {
protected:
    std::string name;
    int x, y;

public:
    NPC(const std::string& name, int x, int y) : name(name), x(x), y(y) {}
    virtual ~NPC() = default;

    virtual std::string fight(std::shared_ptr<NPC> other) = 0;

    std::string getName() const { return name; }
    int getX() const { return x; }
    int getY() const { return y; }
};