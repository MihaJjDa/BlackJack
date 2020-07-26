#pragma once

#include <deque>

#include "Card.h"

class DeckPile {
    std::deque<Card> _cards;
public:
    DeckPile(int countDecks = 4);
    ~DeckPile() = default;
    DeckPile(const DeckPile& game) = delete;
    DeckPile& operator=(const DeckPile& game) = delete;
    DeckPile(DeckPile&& game) = default;
    DeckPile& operator=(DeckPile&& game) = default;

    Card giveCard();
    void shuffle();

    bool empty() const;
    int size() const;
};