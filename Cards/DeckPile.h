#pragma once

#include <deque>

#include "Card.h"

class DeckPile {
    std::deque<Card> _cards;
public:
    DeckPile(int countDecks = 4);

    Card giveCard();

    bool empty() const;
    int size() const;
private:
    void shuffle();
};