#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int numberPlayers) {
    countPlayers = numberPlayers;
}

void BlackJackGame::makePlayers() {
    for (int i = 0; i < countPlayers; i++)
        players.push_back(Player());
}

void BlackJackGame::makeDealer() {
    dealer = Dealer();
}

void BlackJackGame::connectGame() {
    dealer.addPlayers(&players);
    for (int i = 0; i < countPlayers; i++)
        players[i].addDealer(&dealer);
}

void BlackJackGame::startGame() {
    dealer.startRound();
}