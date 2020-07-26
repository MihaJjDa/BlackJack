/*
#include "IPlayer.h"
#include "Player.h"


class Player;

class Dealer: public IPlayer {
    std::vector<Player> *_players;
    int _countDeck;
    DeckPile *_deck;
    Card *_closedCard;
    bool _cardIsClosed;
public:
    Dealer(int numberDeck = 4);
    ~Dealer();
    Dealer(const Dealer& player) = delete;
    Dealer& operator=(const Dealer& player) = delete;
    Dealer(Dealer&& player) = delete ;
    Dealer& operator=(Dealer&& player) = delete;

    Card handOut();
    void addPlayers(std::vector<Player> *players);
    void makeDeckPile();
    void handOutAll();
    void play() override;
    void bust() override;

    bool allPlayersBusted() const;
    void passMove(Player *player) const;
    void resolve(Player *player) const;
    void show() const override;
};
 */
