#include "gtest/gtest.h"

#include <Card.h>

TEST(Card, Usage) {
    Card a(Ranks::TEN, Suits::DIAMONDS);
    Card b(Ranks::ACE, Suits::CLUBS);
    a.show('\n');
    a = b;
    a.show('\n');
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
