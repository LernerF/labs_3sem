#include <gtest/gtest.h>
#include "../src/NPC/SlaveTrader.hpp"
#include "../src/NPC/Squirrel.hpp"
#include "../src/NPC/WanderingKnight.hpp"

// Тестирование NPC классов
TEST(NPC, SlaveTraderFight) {
    auto trader = std::make_shared<SlaveTrader>("Торгаш1", 100, 100);
    auto squirrel = std::make_shared<Squirrel>("Белка1", 105, 105);
    auto knight = std::make_shared<WanderingKnight>("Рыцарь1", 200, 200);

    EXPECT_EQ(trader->fight(squirrel), "Торгаш1 (Работорговец) убивает Белка1 (Белка).");
    EXPECT_EQ(trader->fight(knight), "Рыцарь1 (Рыцарь) убивает Торгаш1 (Работорговец).");
}

TEST(NPC, SquirrelFight) {
    auto squirrel1 = std::make_shared<Squirrel>("Белка1", 100, 100);
    auto squirrel2 = std::make_shared<Squirrel>("Белка2", 101, 101);

    EXPECT_EQ(squirrel1->fight(squirrel2), "Белка1 (Белка) убивает Белка2 (Белка).");
}