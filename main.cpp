#include "BlackJackGame.h"

int main() {
    int numberPlayers, numberBots;
    std::cout << "BlackJack by MihaJjDa" << std::endl;
    std::cout << "Number of players: ";
    std::cin >> numberPlayers;
    std::cout << "Number of bots: ";
    std::cin >> numberBots;

    BlackJackGame game(numberPlayers, numberBots, 100, 4);

    game.addPlayers();
    game.connectGame();
    game.startGame();

    return 0;
}
