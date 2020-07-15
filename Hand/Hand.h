#pragma once

#include <vector>

#include "Card.h"

class Hand {
    std::vector<Card> cards;
public:
    Hand();
    void addCard(Card card);
    bool empty();
    int totalValue();
    void show();
    ~Hand();
};