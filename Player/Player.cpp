#include "Player.h"



Player::Player() = default;

//void Player::addDealer(Dealer d) { dealer = d; }

int Player::points() {
    return cards.totalValue();
}

Card Player::requestCard() {
    //return dealer.handOut();
    std::cout << "Gimme card" << std::endl;
}

void Player::addCard(Card card) {
    cards.addCard(card);
}

char Player::makeDecision() {
    char c;
    std::cout << "Your turn: ";
    std::cin >> c;
    return c;
}

void Player::bust() {
    busted = true;
}

bool Player::isBusted() {
    return busted;
}

void Player::play() {
    char c;
    do {
        c = makeDecision();
        if (c == 'h')
            addCard(requestCard());
    } while (c != 's' and cards.totalValue() < 21);
}