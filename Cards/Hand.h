#pragma once

#include <deque>

#include "Card.h"

class Hand {
    std::deque<Card> _cards;
public:
    Hand();
    ~Hand() = default;
    Hand(const Hand& game) = delete;
    Hand& operator=(const Hand& game) = delete;
    Hand(Hand&& game) = default;
    Hand& operator=(Hand&& game) = default;

    void addCard(Card card);

    //bool empty() const;
    int totalValue() const;
    void show() const;
};