#include "Deck.h"



Deck::Deck() {
    Ranks ranks[13] = {Ranks::TWO, Ranks::THREE, Ranks::FOUR, Ranks::FIVE,
                       Ranks::SIX, Ranks::SEVEN, Ranks::EIGHT, Ranks::NINE,
                       Ranks::TEN, Ranks::JACK, Ranks::QUEEN, Ranks::KING,
                       Ranks::ACE};
    Suits suits[4] = {Suits::CLUBS, Suits::DIAMONDS,
                      Suits::HEARTS, Suits::SPADES};
    for (int i = 0; i < 13; i++)
        for (int j = 0; j < 4; j++)
            _cards.push_back(Card(ranks[i], suits[j]));
}

Deck::~Deck() {
    _cards.clear();
};

Card Deck::giveCard() {
    Card card = _cards.back();
    _cards.pop_back();
    return card;
}

bool Deck::empty() const {
    return _cards.empty();
}
