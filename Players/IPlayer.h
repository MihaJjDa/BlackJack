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

    virtual void bust() = 0;

    virtual bool gameIsOn() const = 0;
    virtual void show() const = 0;
};