#include "Dealer.h"



Dealer::Dealer(): Player() {};

void Dealer::makeDeckPile() {
    deck = DeckPile(countDeck);
    deck.shuffle();
}

void Dealer::handOut(Player player) {
    player.addCard(deck.giveCard());
}

void Dealer::handOutAll() {
    for (auto player : players)
        handOut(player);
}

void Dealer::StartRound() {
    if (deck.size() < (players.size()+1)*15)
        makeDeckPile();
    handOutAll();
    handOut(*this);
    handOutAll();
    closedCard = deck.giveCard();
    if (cards)
}

void passMove(Player player);