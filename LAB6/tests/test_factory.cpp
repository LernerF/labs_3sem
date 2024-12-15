#include <gtest/gtest.h>
#include "../src/patterns/Factory.hpp"

// Тестирование Factory
TEST(Factory, CreateNPC) {
    auto trader = NPCFactory::createNPC("Работорговец", "Торгаш1", 100, 100);
    auto squirrel = NPCFactory::createNPC("Белка", "Белка1", 105, 105);
    auto knight = NPCFactory::createNPC("Странствующий рыцарь", "Рыцарь1", 200, 200);

    EXPECT_EQ(trader->getName(), "Торгаш1");
    EXPECT_EQ(squirrel->getName(), "Белка1");
    EXPECT_EQ(knight->getName(), "Рыцарь1");

    EXPECT_EQ(trader->getX(), 100);
    EXPECT_EQ(knight->getY(), 200);
}

TEST(Factory, InvalidNPCType) {
    EXPECT_THROW(NPCFactory::createNPC("Неизвестный", "NPC1", 0, 0), std::invalid_argument);
}