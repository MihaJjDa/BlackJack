#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int numberPlayers)
    : _players(std::vector<Player>())
    , _dealer(Dealer())
    , _countPlayers(numberPlayers) {
    for (int i = 0; i < _countPlayers; i++)
        _players.push_back(Player());
}

BlackJackGame::~BlackJackGame() {
    _players.clear();
}

void BlackJackGame::connectGame() {
    _dealer.addPlayers(&_players);
    for (int i = 0; i < _countPlayers; i++)
        _players[i].addDealer(&_dealer);
}

void BlackJackGame::startGame() {
    _dealer.startRound();
}