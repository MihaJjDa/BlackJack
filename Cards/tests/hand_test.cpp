#include "gtest/gtest.h"

#include "Hand.h"

TEST(Hand, Usage) {
    Hand a;
    ASSERT_EQ(a.totalValue(), 0);
    a.addCard(Card(Ranks::TWO, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 2);
    a.addCard(Card(Ranks::ACE, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 13);
    a.addCard(Card(Ranks::THREE, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 16);
    a.addCard(Card(Ranks::FIVE, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 21);
    a.addCard(Card(Ranks::JACK, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 21);
    a.addCard(Card(Ranks::QUEEN, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 31);
    a.addCard(Card(Ranks::KING, Suits::HEARTS));
    ASSERT_EQ(a.totalValue(), 41);
    a.addCard(Card(Ranks::KING, Suits::CLUBS));
    ASSERT_EQ(a.totalValue(), 51);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
