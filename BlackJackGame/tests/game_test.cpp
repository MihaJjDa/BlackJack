#include "gtest/gtest.h"

#include "BlackJackGame.h"

TEST(BlackJackGame, Usage) {
    BlackJackGame game;
    game.connectGame();
}

int main(int argc, char *argv[]) {
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
