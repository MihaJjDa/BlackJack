#pragma once

#include <deque>

#include "DeckPile.h"
#include "IHolder.h"
#include "IPlayer.h"

class IPlayer;

class Dealer: public IHolder {
    std::deque<IPlayer*> *_players;
    int _countDeck;
    DeckPile _deck;
    Card _closedCard;
    bool _cardIsClosed;
public:
    Dealer(int numberDeck = 4);

    void addPlayers(std::deque<IPlayer*> *players);
    std::deque<IPlayer*> playRound();

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

    std::deque<IPlayer*> outPlayers() const;
    void play() override;

    void addOpenedCard();
    void setClosedCard();
    void addClosedCard();

    bool allPlayersBusted() const;
    void resolve(IPlayer *player) const;
};