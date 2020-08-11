#pragma once

#include <string>

#include "IHolder.h"
#include "Dealer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD

class Dealer;

class IPlayer : public IHolder {
protected:
    std::string _name;
    Dealer *_dealer;
    int _cash;
    int _bet;
    bool _doubled;
public:
    IPlayer(std::string name, Dealer *dealer = nullptr, int initCash = 100);

    void makeBet();
    void play() override;
    void lose();
    void win1_0Bet();
    void win1_5Bet();

    void draw() const;
    bool gameIsOn() const;
    void lookAtCards() const;
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