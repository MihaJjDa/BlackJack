#include <vector>

#include "Deck.h"

class DeckPile {
    std::vector<Card> cards;
    int countCards;
public:
    DeckPile(int countDecks = 4);
    Card giveCard();
    int size();
    bool empty();
    void shuffle();
    ~DeckPile();
};