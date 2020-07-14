#include "BlackJackGame.h"

int main() {
    BlackJackGame game;
    game.makeDealer();
    game.makePlayers();
    game.connectGame();
    game.startGame();
    return 0;
}
