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
    void play() override;

    void lose();
    void win1_0Bet();
    void win1_5Bet();
    void draw() const;

    bool gameIsOn() const override;

    void lookAtCards() const;
private:
    void show() const override;
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

    void addPlayers(std::vector<Player> *players);
    bool playRound();

    Card handOut();
    void show() const override;
private:
    void setRound();
    void makeDeckPile();
    void allSetHand() const;
    void allMakeBet() const;
    void allHandOut();
    void allLookAtCards() const;
    void allDoubleBet() const;
    void allPlay() const;
    void allResolve() const;

    bool gameIsOn() const override;
    void play() override;

    void addOpenedCard();
    void setClosedCard();
    void addClosedCard();

    bool allPlayersBusted() const;
    void resolve(Player *player) const;
};