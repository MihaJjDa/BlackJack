#pragma once

#include "Hand.h"



class IPlayer {
protected:
    Hand _cards;
public:
    IPlayer() = default;

    void addCard(Card card);

    int points() const;
    bool isBusted() const;

    virtual void play() = 0;
    virtual void bust() = 0;

    virtual void show() const = 0;
};