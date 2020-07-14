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
    void addPlayers(std::vector<Player> p);
    void makeDeckPile();
    Card handOut();
    void handOutAll();
    void StartRound();
    void passMove(Player player);
};
