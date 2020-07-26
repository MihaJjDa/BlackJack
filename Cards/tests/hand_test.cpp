#include "gtest/gtest.h"

#include "Hand.h"

TEST(Hand, Usage) {
    Hand a;
    a.addCard(Card(Ranks::TWO, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::ACE, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::THREE, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::FIVE, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::JACK, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::QUEEN, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::KING, Suits::HEARTS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(Ranks::KING, Suits::CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
