#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int numberPlayers,
                             int numberBots,
                             int initCash,
                             int numberDecks)
    : _countPlayers(numberPlayers)
    , _countBots(numberBots)
    , _initCash(initCash)
    , _dealer(Dealer(numberDecks)) {}

void BlackJackGame::addPlayers() {
    std::string name;
    _players.clear();
    for (int i = 0; i < _countPlayers; i++) {
        std::cout << "Input name of player #" << i+1 << ": ";
        std::cin >> name;
        _players.push_back(new Player(name, &_dealer, _initCash));
    }
    for (int i = 0; i < _countBots; i++)
        _players.push_back(new Player("Bot" + std::to_string(i+1),
                                         &_dealer,
                                         _initCash));
}

void BlackJackGame::connectGame() {
    _dealer.addPlayers(&_players);
}

void BlackJackGame::startGame() {
    do {
        std::cout << std::endl;
        std::deque<IPlayer*> outPlayers = _dealer.playRound();
        for (auto p = _players.begin(); p < _players.end(); p++) {
            if (*p == outPlayers.front()) {
                delete *p;
                _players.erase(p);
                outPlayers.pop_front();
            }
        }
    } while (not _players.empty());
}
