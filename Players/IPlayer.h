#pragma once

#include "Hand.h"
#include "DeckPile.h"



class IPlayer {
protected:
    Hand *_cards;
    bool _busted;
public:
    IPlayer();
    ~IPlayer();
    IPlayer(const IPlayer &player) = delete;
    IPlayer& operator=(const IPlayer &player) = delete;
    IPlayer(IPlayer&& player) = delete;
    IPlayer& operator=(IPlayer&& player) = delete;

    void addCard(Card card);

    int points() const;
    bool isBusted() const;

    virtual void play() = 0;
    virtual void bust() = 0;

    virtual void show() const = 0;
};