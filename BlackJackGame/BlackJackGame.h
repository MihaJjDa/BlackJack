#include <vector>

//#include "Dealer.h"
#include "Player.h"

class BlackJackGame {
public:
    std::vector<Player> players;
    Dealer dealer;
    int countPlayers;
public:
    BlackJackGame(int numberPlayers = 1);
    void makePlayers();
    void makeDealer();
    void connectGame();
    void startGame();
};

