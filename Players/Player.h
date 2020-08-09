#pragma once

#include <string>

#include "IPlayer.h"
#include "Dealer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD

class Player : public IPlayer {
protected:
    std::string _name;
    Dealer *_dealer;
    int _cash;
    int _bet;
    bool _doubled;
public:
    Player(std::string name, Dealer *dealer = nullptr, int initCash = 100);

    void makeBet() override;
    void play() override;
    void lose() override;
    void win1_0Bet() override;
    void win1_5Bet() override;

    void draw() const override;
    bool gameIsOn() const override;
    void lookAtCards() const override;
private:
    void setTurn() const;
    char playTurn(bool first);
    void finishTurn() const;
    void show() const override;
protected:
    virtual int bet() const = 0;
    virtual char turn() const = 0;
    virtual bool cont() const = 0;

};