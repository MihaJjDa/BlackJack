#pragma once

#include <deque>

#include "Card.h"

class Hand {
    std::deque<Card> _cards;
public:
    Hand() = default;

    void addCard(Card card);

    int totalValue() const;
    void show() const;
};