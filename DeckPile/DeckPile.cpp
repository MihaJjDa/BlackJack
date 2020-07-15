#include <random>
#include <algorithm>

#include "DeckPile.h"




DeckPile::DeckPile(int countDecks) {
    Deck decks[countDecks];

    countCards = 0;
    for (auto deck : decks) {
        while (!deck.empty()) {
            cards.push_back(deck.giveCard());
            countCards += 1;
        }
    }

    shuffle();
}

DeckPile::~DeckPile() {
    cards.clear();
};

Card DeckPile::giveCard() {
    Card card = cards.back();
    cards.pop_back();
    countCards -= 1;
    return card;
}

bool DeckPile::empty() {
    return cards.empty();
}

int DeckPile::size() {
    return countCards;
}

void DeckPile::shuffle() {
    // TODO: BETTER RANDOM
    std::random_device randomDevice;
    std::default_random_engine engine(randomDevice());

    std::shuffle(cards.begin(), cards.end(), engine);
}