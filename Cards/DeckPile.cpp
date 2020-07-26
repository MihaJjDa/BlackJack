#include <random>
#include <algorithm>

#include "DeckPile.h"



DeckPile::DeckPile(int countDecks) {
    Ranks ranks[13] = {Ranks::TWO, Ranks::THREE, Ranks::FOUR, Ranks::FIVE,
                       Ranks::SIX, Ranks::SEVEN, Ranks::EIGHT, Ranks::NINE,
                       Ranks::TEN, Ranks::JACK, Ranks::QUEEN, Ranks::KING,
                       Ranks::ACE};
    Suits suits[4] = {Suits::CLUBS, Suits::DIAMONDS,
                      Suits::HEARTS, Suits::SPADES};

    for (int k = 0; k < countDecks; k++)
        for (int i = 0; i < 13; i++)
            for (int j = 0; j < 4; j++)
                _cards.push_back(Card(ranks[i], suits[j]));

    shuffle();
}

Card DeckPile::giveCard() {
    Card card = _cards.front();
    _cards.pop_front();
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
    return _cards.size();
}