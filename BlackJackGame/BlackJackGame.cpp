#include "BlackJackGame.h"

BlackJackGame::BlackJackGame(int n) {
    countPlayers = n;
}

void BlackJackGame::makePlayers() {
    for (int i = 0; i < countPlayers; i++)
        players.push_back(Player());
}

void BlackJackGame::makeDealer() {}

void BlackJackGame::connectGame() {
    dealer.addPlayers(players);
    //for (auto player : players) player.addDealer(dealer);
}

void BlackJackGame::startGame() {
    dealer.StartRound();
}