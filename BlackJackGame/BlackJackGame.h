#include <deque>

//#include "Dealer.h"
#include "Player.h"

class BlackJackGame {
public:
    std::deque<Player*> _players;
    int _countPlayers;
    int _initCash;
    Dealer _dealer;
public:
    BlackJackGame(int numberPlayers = 1,
                  int initCash = 100,
                  int numberDecks = 4);

    void addPlayers();
    void connectGame();
    void startGame();
};

