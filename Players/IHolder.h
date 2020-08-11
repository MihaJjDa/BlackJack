#pragma once

#include "Hand.h"



class IHolder {
protected:
    Hand _cards;
public:
    IHolder() = default;

    void addCard(Card card);
    void setHand();

    int points() const;
    bool isBusted() const;

    virtual void play() = 0;

    virtual void show() const = 0;
};