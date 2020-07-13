#include "gtest/gtest.h"

#include "Deck.h"

TEST(Deck, Usage) {
    Deck a;
    while (!a.empty()) {
        Card b = a.giveCard();
        b.show(' ');
    }
    std::cout << std::endl;
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
