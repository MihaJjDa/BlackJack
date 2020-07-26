#include <random>
#include <algorithm>

#include "DeckPile.h"



DeckPile::DeckPile(int countDecks) {
    Deck decks[countDecks];

    for (int i = 0; i < countDecks; i++)
        while (!decks[i].empty())
            _cards.push_back(decks[i].giveCard());

    shuffle();
}

DeckPile::~DeckPile() {
    _cards.clear();
};

Card DeckPile::giveCard() {
    Card card = _cards.back();
    _cards.pop_back();
    //_countCards -= 1;
    return card;
}

void DeckPile::shuffle() {
    // TODO: CEED FOR RANDOM???
    std::random_device randomDevice;
    std::default_random_engine engine(randomDevice());

    std::shuffle(_cards.begin(), _cards.end(), engine);
}

bool DeckPile::empty() const {
    return _cards.empty();
}

int DeckPile::size() const {
    //return _countCards;
    return _cards.size();
}