#pragma once

#include <vector>

#include "Hand.h"
#include "DeckPile.h"


// TODO: INTERFACES IPlayer ICards or BasePlayer BaseCards if no pure virtual
// TODO: TESTS IN ASSERTS FOR EVERY METHOD

class Dealer;

class Player {
    Dealer *_dealer;
protected:
    Hand *_cards;
    bool _busted;
public:
    Player();
    ~Player();
    Player(const Player &player) = delete;
    Player& operator=(const Player &player) = delete;
    Player(Player&& player);
    Player& operator=(Player&& player);

    void addDealer(Dealer *d);
    void addCard(Card card);
    void play();
    virtual void bust();

    int points() const;
    Card requestCard() const;
    char makeDecision() const;
    bool isBusted() const;
    void blackJack() const;
    void lose() const;
    void draw() const;
    void win1_0Bet() const;
    void win1_5Bet() const;
    void lookAtCards() const;
    virtual void show() const;
};

class Dealer: public Player {
    std::vector<Player> *_players;
    Card *_closedCard;
    bool _cardIsClosed;
    int _countDeck;
    DeckPile *_deck;
public:
    Dealer(int numberDeck = 4);
    ~Dealer();
    Dealer(const Dealer& player) = delete;
    Dealer& operator=(const Dealer& player) = delete;
    Dealer(Dealer&& player) = delete ;
    Dealer& operator=(Dealer&& player) = delete;

    Card handOut();
    void addPlayers(std::vector<Player> *players);
    void makeDeckPile();
    void handOutAll();
    void startRound();
    void bust() override;

    bool allPlayersBusted() const;
    void passMove(Player *player) const;
    void resolve(Player *player) const;
    void show() const override;
};