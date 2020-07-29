#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int numberPlayers,
                             int initCash,
                             int numberDecks)
    : _countPlayers(numberPlayers)
    , _initCash(initCash)
    , _dealer(Dealer(numberDecks)) {}

void BlackJackGame::addPlayers() {
    std::string name;
    _players.clear();
    for (int i = 0; i < _countPlayers; i++) {
        std::cout << "Input name of player #" << i << ": ";
        std::cin >> name;
        _players.push_back(Player(name, &_dealer, _initCash));
    }
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