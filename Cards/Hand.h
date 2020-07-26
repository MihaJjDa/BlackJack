#pragma once

#include <vector>

#include "Card.h"

class Hand {
    std::vector<Card> _cards;
public:
    Hand();
    ~Hand();
    Hand(const Hand& game) = delete;
    Hand& operator=(const Hand& game) = delete;
    Hand(Hand&& game) = default;
    Hand& operator=(Hand&& game) = default;

    void addCard(Card card);

    bool empty() const;
    int totalValue() const;
    void show() const;
};