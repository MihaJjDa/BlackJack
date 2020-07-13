#include "Deck.h"



Deck::Deck() {
    Ranks ranks[13] = {TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE,
                       TEN, JACK, QUEEN, KING, ACE};
    Suits suits[4] = {CLUBS, DIAMONDS, HEARTS, SPADES};
    for (auto suit : suits)
        for (auto rank : ranks)
            cards.push_back(Card(rank, suit));
}

Deck::~Deck() {
    cards.clear();
};

Card Deck::giveCard() {
    Card card = cards.back();
    cards.pop_back();
    return card;
}

bool Deck::empty() {
    return cards.empty();
}
