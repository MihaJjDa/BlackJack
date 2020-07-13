#include <vector>

#include "Player.h"
#include "DeckPile.h"

class Dealer: public Player {
    Card closedCard;
    std::vector<Player> players;
    int countDeck = 4;
    DeckPile deck;
public:
    Dealer();
    void makeDeckPile();
    void handOut(Player player);
    void handOutAll();
    void StartRound();
    void passMove(Player player);
};
