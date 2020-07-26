#pragma once

#include <vector>
#include "IPlayer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD
// TODO: OWN FILES FOR DEALER


class Dealer;

class Player : public IPlayer {
    Dealer *_dealer;
public:
    Player();
    ~Player() = default;
    Player(const Player &player) = delete;
    Player& operator=(const Player &player) = delete;
    Player(Player&& player);
    Player& operator=(Player&& player);

    void addDealer(Dealer *d);

    void blackJack() const;
    void lose() const;
    void draw() const;
    void win1_0Bet() const;
    void win1_5Bet() const;

    void play() override;
    void bust() override;

    void show() const override;
private:
    Card requestCard() const;
    char makeDecision() const;
};



class Dealer: public IPlayer {
    std::vector<Player> *_players;
    int _countDeck;
    DeckPile *_deck;
    Card *_closedCard;
    bool _cardIsClosed;
public:
    Dealer(int numberDeck = 4);
    ~Dealer();
    Dealer(const Dealer& player) = delete;
    Dealer& operator=(const Dealer& player) = delete;
    Dealer(Dealer&& player) = delete ;
    Dealer& operator=(Dealer&& player) = delete;

    Card handOut();
    void addPlayers(std::vector<Player> *players);

    void play() override;
private:
    void makeDeckPile();
    void handOutAll();

    bool allPlayersBusted() const;
    void passMove(Player *player) const;
    void resolve(Player *player) const;

    void bust() override;

    void show() const override;
};