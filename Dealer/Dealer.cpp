#include "Dealer.h"



Dealer::Dealer(): Player() {}

void Dealer::addPlayers(std::vector<Player> p) {
    players = p;
}

void Dealer::makeDeckPile() {
    deck = DeckPile(countDeck);
    deck.shuffle();
}

Card Dealer::handOut() {
    return deck.giveCard();
}

void Dealer::handOutAll() {
    for (auto player : players)
        player.addCard(handOut());
}

void Dealer::StartRound() {
    if (deck.size() < (players.size()+1)*15)
        makeDeckPile();

    handOutAll();
    addCard(handOut());
    handOutAll();
    closedCard = deck.giveCard();

    if (points() >= 10)
        addCard(closedCard);

    if (points() < 21) {
        for (auto player : players)
            passMove(player);
        while (points() < 17)
            addCard(deck.giveCard());
        if (points() > 21)
            bust();
    }

    for (auto player : players)
        if (player.isBusted())
            std::cout << "You lose" << std::endl;
        else if (isBusted())
            if (player.points() == 21)
                std::cout << "You win 3/2" << std::endl;
            else
                std::cout << "You win 1" << std::endl;
        else
            if (player.points() < points())
                std::cout << "You lose" << std::endl;
            else if (player.points() == points())
                std::cout << "Draw" << std::endl;
            else if (player.points() == 21)
                std::cout << "You win 3/2" << std::endl;
            else
                std::cout << "You win 1" << std::endl;
}

void Dealer::passMove(Player player) {
    player.play();
    if (player.points() > 21)
        player.bust();
}