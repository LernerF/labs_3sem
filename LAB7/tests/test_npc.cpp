#include "npc.hpp"
#include <gtest/gtest.h>

TEST(NPCTest, CreateNPC) {
    NPC npc("Trader1", NPC::Type::TRADER, 10, 20);
    EXPECT_EQ(npc.getName(), "Trader1");
    EXPECT_EQ(npc.getType(), NPC::Type::TRADER);
    EXPECT_EQ(npc.getX(), 10);
    EXPECT_EQ(npc.getY(), 20);
    EXPECT_TRUE(npc.isAlive());
}

TEST(NPCTest, MoveNPC) {
    NPC npc("Squirrel1", NPC::Type::SQUIRREL, 0, 0);
    npc.move(5, 5, 100, 100);
    EXPECT_EQ(npc.getX(), 5);
    EXPECT_EQ(npc.getY(), 5);

    npc.move(-10, -10, 100, 100);
    EXPECT_EQ(npc.getX(), 0);
    EXPECT_EQ(npc.getY(), 0);
}