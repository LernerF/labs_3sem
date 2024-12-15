#include "map.hpp"
#include "npc_factory.hpp"
#include <gtest/gtest.h>

TEST(MapTest, AddNPC) {
    Map map;
    auto npc = NPCFactory::createNPC("Trader1", NPC::Type::TRADER, 100, 100);
    map.addNPC(npc);

    auto npcs = map.getAliveNPCs();
    EXPECT_EQ(npcs.size(), 1);
    EXPECT_EQ(npcs[0]->getName(), "Trader1");
}

TEST(MapTest, DisplayNPC) {
    Map map;
    auto npc1 = NPCFactory::createNPC("Trader1", NPC::Type::TRADER, 100, 100);
    auto npc2 = NPCFactory::createNPC("Squirrel1", NPC::Type::SQUIRREL, 50, 50);

    map.addNPC(npc1);
    map.addNPC(npc2);

    testing::internal::CaptureStdout();
    map.display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_TRUE(output.find("Trader1") != std::string::npos);
    EXPECT_TRUE(output.find("Squirrel1") != std::string::npos);
}