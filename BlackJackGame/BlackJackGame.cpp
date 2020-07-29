#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int numberPlayers,
                             int initCash,
                             int numberDecks)
    : _countPlayers(numberPlayers)
    , _initCash(initCash)
    , _dealer(Dealer(numberDecks)) {}

void BlackJackGame::addPlayers() {
    _players.clear();
    for (int i = 0; i < _countPlayers; i++)
        _players.push_back(Player(&_dealer, _initCash));
}

void BlackJackGame::connectGame() {
    _dealer.addPlayers(&_players);
}

void BlackJackGame::startGame() {
    bool gameOn;
    do {
        std::cout << std::endl;
        gameOn = _dealer.playRound();
    } while (gameOn);

}