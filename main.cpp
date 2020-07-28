#include "BlackJackGame.h"

int main() {
    std::cout << "BlackJack by MihaJjDa" << std::endl;

    BlackJackGame game(1, 100, 4);

    game.addPlayers();
    game.connectGame();
    game.startGame();

    return 0;
}
