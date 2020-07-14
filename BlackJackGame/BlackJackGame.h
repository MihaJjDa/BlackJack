#include <vector>

#include "Dealer.h"

class BlackJackGame {
    std::vector<Player> players;
    Dealer dealer;
    int countPlayers;
public:
    BlackJackGame(int n);
    void makePlayers();
    void makeDealer();
    void connectGame();
    void startGame();
};

