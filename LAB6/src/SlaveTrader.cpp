#include "SlaveTrader.hpp"
#include "Squirrel.hpp"
#include "WanderingKnight.hpp"

std::string SlaveTrader::fight(std::shared_ptr<NPC> other) {
    if (typeid(*other) == typeid(SlaveTrader)) {
        return name + " (Работорговец) и " + other->getName() + " погибли в бою.";
    }
    if (typeid(*other) == typeid(Squirrel)) {
        return name + " (Работорговец) убивает " + other->getName() + " (Белка).";
    }
    if (typeid(*other) == typeid(WanderingKnight)) {
        return other->getName() + " (Рыцарь) убивает " + name + " (Работорговец).";
    }
    return "Неизвестный исход битвы.";
}