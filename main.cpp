#include "BlackJackGame.h"

int main() {
    std::cout << "BlackJack by MihaJjDa" << std::endl;
    std::cout << "Press h to hit, s to stand" << std::endl;
    std::cout << "Another characters are not supported, sry" << std::endl;

    BlackJackGame game;
    game.connectGame();
    game.startGame();
    return 0;
}
