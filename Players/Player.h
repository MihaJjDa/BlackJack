#pragma once

#include <vector>
#include <string>

#include "IPlayer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD
// TODO: OWN FILES FOR DEALER


class Dealer;

class Player : public IPlayer {
    std::string _name;
    Dealer *_dealer;
    int _cash;
    int _bet;
    bool _doubled;
public:
    Player(std::string name, Dealer *dealer = nullptr, int initCash = 100);

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
};



#include <deque>

#include "DeckPile.h"



class Dealer: public IPlayer {
    std::deque<Player*> *_players;
    int _countDeck;
    DeckPile _deck;
    Card _closedCard;
    bool _cardIsClosed;
public:
    Dealer(int numberDeck = 4);

    void addPlayers(std::deque<Player*> *players);
    std::deque<Player*> playRound();

    Card handOut();
    void show() const override;
private:
    void setRound();
    void makeDeckPile();
    void allSetHand() const;
    void allMakeBet() const;
    void allHandOut();
    void allLookAtCards() const;
    void allPlay() const;
    void allResolve() const;

    std::deque<Player*> gameIsOn() const;
    void play() override;

    void addOpenedCard();
    void setClosedCard();
    void addClosedCard();

    bool allPlayersBusted() const;
    void resolve(Player *player) const;
};