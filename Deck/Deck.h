#include <vector>

#include "Card.h"

class Deck {
    std::vector<Card> cards;
public:
    Deck();
    Card giveCard();
    bool empty();
    ~Deck();
};