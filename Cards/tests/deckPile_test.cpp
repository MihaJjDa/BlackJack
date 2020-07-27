#include "gtest/gtest.h"

#include "DeckPile.h"



TEST(DeckPile, Usage) {
    DeckPile a;
    ASSERT_EQ(a.size(), 208);
    ASSERT_FALSE(a.empty());
    while (!a.empty()) {
        Card b = a.giveCard();
    }
    ASSERT_EQ(a.size(), 0);
    ASSERT_TRUE(a.empty());
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
