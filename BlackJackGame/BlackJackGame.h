#pragma once

#include <deque>

#include "Dealer.h"
#include "Player.h"

class BlackJackGame {
public:
    std::deque<IPlayer*> _players;
    int _countPlayers;
    int _countBots;
    int _initCash;
    Dealer _dealer;
public:
    BlackJackGame(int numberPlayers = 1,
                  int numberBots = 0,
                  int initCash = 100,
                  int numberDecks = 4);

    void addPlayers();
    void connectGame();
    void startGame();
};

