#include "gtest/gtest.h"

#include <Card.h>

// TODO: TESTS FOR OUTPUT?

TEST(Card, Usage) {
    ASSERT_EQ(Card(Ranks::TWO, Suits::CLUBS).value(), 2);
    ASSERT_EQ(Card(Ranks::THREE, Suits::DIAMONDS).value(), 3);
    ASSERT_EQ(Card(Ranks::FOUR, Suits::HEARTS).value(), 4);
    ASSERT_EQ(Card(Ranks::FIVE, Suits::SPADES).value(), 5);
    ASSERT_EQ(Card(Ranks::SIX, Suits::CLUBS).value(), 6);
    ASSERT_EQ(Card(Ranks::SEVEN, Suits::DIAMONDS).value(), 7);
    ASSERT_EQ(Card(Ranks::EIGHT, Suits::HEARTS).value(), 8);
    ASSERT_EQ(Card(Ranks::NINE, Suits::SPADES).value(), 9);
    ASSERT_EQ(Card(Ranks::TEN, Suits::CLUBS).value(), 10);
    ASSERT_EQ(Card(Ranks::JACK, Suits::DIAMONDS).value(), 10);
    ASSERT_EQ(Card(Ranks::QUEEN, Suits::HEARTS).value(), 10);
    ASSERT_EQ(Card(Ranks::KING, Suits::SPADES).value(), 10);
    ASSERT_EQ(Card(Ranks::ACE, Suits::CLUBS).value(), 11);
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
