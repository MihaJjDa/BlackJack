#include <vector>

#include "Hand.h"



class Player {
    Hand cards;
    //    Dealer dealer;
    bool busted = 0;
public:
    Player();
    //void addDealer(Dealer d);
    int points();
    Card requestCard();
    void addCard(Card card);
    char makeDecision();
    void bust();
    bool isBusted();
    void play();
};
