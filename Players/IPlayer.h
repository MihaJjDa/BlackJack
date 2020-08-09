#pragma once

#include "Hand.h"



class IPlayer {
protected:
    Hand _cards;
public:
    IPlayer() = default;

    void addCard(Card card);
    void setHand();

    int points() const;
    bool isBusted() const;

    virtual void makeBet() {}
    virtual void play() = 0;
    virtual void lose() {}
    virtual void win1_0Bet() {}
    virtual void win1_5Bet() {}

    virtual void draw() const {}
    virtual bool gameIsOn() const {}
    virtual void lookAtCards() const {}
    virtual void show() const = 0;
};