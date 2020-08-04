#include "BlackJackGame.h"

int main() {
    int numberPlayers;
    std::cout << "BlackJack by MihaJjDa" << std::endl;
    std::cout << "Number of players: ";
    std::cin >> numberPlayers;

    BlackJackGame game(numberPlayers, 100, 4);

    game.addPlayers();
    game.connectGame();
    game.startGame();

    return 0;
}
