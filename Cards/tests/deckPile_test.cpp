#include "gtest/gtest.h"

#include "DeckPile.h"



TEST(DeckPile, Usage) {
    DeckPile a;
    ASSERT_EQ(a.size(), 208);
    while (!a.empty()) {
        Card b = a.giveCard();
        b.show(' ');
    }
    std::cout << std::endl;
    ASSERT_EQ(a.size(), 0);

    DeckPile c;
    c.shuffle();
    while (!c.empty()) {
        Card b = c.giveCard();
        b.show(' ');
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
