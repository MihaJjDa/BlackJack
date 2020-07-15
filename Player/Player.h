#pragma once

#include <vector>

#include "Hand.h"
//#include "Dealer.h"
#include "DeckPile.h"

class Dealer;

class Player {
    Dealer *dealer;
protected:
    Hand cards;
    bool busted = false;
public:
    void addDealer(Dealer *d);
    int points();
    Card requestCard();
    void addCard(Card card);
    void play();
    char makeDecision();
    virtual void show();
    void lookAtCards();
    bool isBusted();
    virtual void bust();
    void blackJack();
    void lose();
    void draw();
    void win1_0Bet();
    void win1_5Bet();
};

class Dealer: public Player {
    std::vector<Player> *players;
    Card closedCard;
    int countDeck;
    DeckPile deck;
public:
    Dealer(int numberDeck = 4);
    void addPlayers(std::vector<Player> *p);
    void makeDeckPile();
    Card handOut();
    void handOutAll();
    void startRound();
    void passMove(Player *player);
    void resolve(Player *player);
    void show() override;
    void bust() override;
    bool allPlayersBusted();
};