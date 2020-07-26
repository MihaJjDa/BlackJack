#pragma once

#include <vector>

#include "Card.h"

class Deck {
    std::vector<Card> _cards;
public:
    Deck();
    ~Deck();
    Deck(const Deck& game) = delete;
    Deck& operator=(const Deck& game) = delete;
    Deck(Deck&& game) = default;
    Deck& operator=(Deck&& game) = default;

    Card giveCard();

    bool empty() const;
};