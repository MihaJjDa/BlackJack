#include <vector>

//#include "Dealer.h"
#include "Player.h"

class BlackJackGame {
public:
    std::vector<Player> _players;
    Dealer _dealer;
    int _countPlayers;
public:
    BlackJackGame(int numberPlayers = 1);
    ~BlackJackGame();
    BlackJackGame(const BlackJackGame& game) = delete;
    BlackJackGame& operator=(const BlackJackGame& game) = delete;
    BlackJackGame(BlackJackGame&& game) = delete;
    BlackJackGame& operator=(BlackJackGame&& game) = delete;

    void connectGame();
    void startGame();
};

