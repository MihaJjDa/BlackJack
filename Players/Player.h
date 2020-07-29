#pragma once

#include <vector>
#include "IPlayer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD
// TODO: OWN FILES FOR DEALER


class Dealer;

class Player : public IPlayer {
    Dealer *_dealer;
    int _cash;
    int _bet;
public:
    Player(Dealer *dealer = nullptr, int initCash = 100);

    void makeBet();
    void doubleBet();
    void lose();
    void win1_0Bet();
    void win1_5Bet();

    bool gameIsOn() const;
    void blackJack() const;
    void draw() const;
    void lookAtCards() const;

    void play();
    void bust() override;

    void show() const override;
private:
    Card requestCard() const;
    char makeDecision() const;
};



#include "DeckPile.h"



class Dealer: public IPlayer {
    std::vector<Player*> _players;
    int _countDeck;
    DeckPile _deck;
    Card _closedCard;
    bool _cardIsClosed;
public:
    Dealer(int numberDeck = 4);

    Card handOut();
    void addPlayers(std::vector<Player> *players);

    bool play();
private:
    void makeDeckPile();
    void handOutAll();

    bool allPlayersBusted() const;
    void passMove(Player *player) const;
    void resolve(Player *player) const;

    void bust() override;

    bool gameIsOn() const override;
    void show() const override;
};