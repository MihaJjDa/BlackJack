#include "gtest/gtest.h"

#include "Player.h"

TEST(Player, Usage) {
    Player p;
    p.addCard(Card(Ranks::JACK, Suits::SPADES));
    ASSERT_EQ(p.points(), 10);
    p.addCard(Card(Ranks::JACK, Suits::SPADES));
    ASSERT_FALSE(p.isBusted());
    ASSERT_EQ(p.points(), 20);
    p.addCard(Card(Ranks::ACE, Suits::SPADES));
    ASSERT_FALSE(p.isBusted());
    ASSERT_EQ(p.points(), 21);
    p.addCard(Card(Ranks::ACE, Suits::SPADES));
    ASSERT_FALSE(p.isBusted());
    ASSERT_EQ(p.points(), 22);
    p.bust();
    ASSERT_TRUE(p.isBusted());
}

TEST(Dealer, Usage) {

}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
