#include "gtest/gtest.h"

#include "Hand.h"

TEST(Hand, Usage) {
    Hand a;
    a.addCard(Card(TWO, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(ACE, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(THREE, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(FIVE, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(JACK, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(QUEEN, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(KING, HEARTS));
    std::cout << a.totalValue() << std::endl;
    a.show();
    a.addCard(Card(KING, CLUBS));
    std::cout << a.totalValue() << std::endl;
    a.show();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
