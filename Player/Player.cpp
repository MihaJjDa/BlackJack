#pragma once

#include "Player.h"



void Player::addDealer(Dealer *d) {
    dealer = d;
}

int Player::points() {
    return cards.totalValue();
}

Card Player::requestCard() {
    return dealer->handOut();
}

void Player::addCard(Card card) {
    cards.addCard(card);
}

void Player::play() {
    char c = 'h';
    while (c != 's' and points() < 21) {
        show();
        c = makeDecision();
        if (c == 'h')
            addCard(requestCard());
    }
    if (points() > 21)
        bust();
}

char Player::makeDecision() {
    char c;
    std::cout << "Your turn: ";
    std::cin >> c;
    return c;
}

void Player::show() {
    std::cout << "Your hand: ";
    cards.show();
}

void Player::lookAtCards() {
    show();
}

bool Player::isBusted() {
    return busted;
}

void Player::bust() {
    show();
    std::cout << "You're busted!" << std::endl;
    busted = true;
}

void Player::blackJack() {
    show();
    std::cout << "You've got BlackJack!" << std::endl;
}

void Player::lose() {
    show();
    std::cout << "You lose" << std::endl;
}

void Player::draw() {
    show();
    std::cout << "Draw" << std::endl;
}

void Player::win1_0Bet() {
    show();
    std::cout << "You win 1" << std::endl;
}

void Player::win1_5Bet() {
    show();
    std::cout << "You win 3/2" << std::endl;
}



Dealer::Dealer(int numberDeck) {
    countDeck = numberDeck;
}

void Dealer::addPlayers(std::vector<Player> *p) {
    players = p;
}

void Dealer::makeDeckPile() {
    deck = DeckPile(countDeck);
}

Card Dealer::handOut() {
    return deck.giveCard();
}

void Dealer::handOutAll() {
    for (int i = 0; i < players->size(); i++)
        (*players)[i].addCard(handOut());
}

// TODO: TOO BIG FUNCTION
void Dealer::startRound() {
    std::cout << std::endl;

    if (deck.size() < (players->size()+1)*15)
        makeDeckPile();

    handOutAll();
    addCard(handOut());
    handOutAll();
    closedCard = deck.giveCard();

    show();

    if (points() >= 10) {
        for (int i = 0; i < players->size(); i++)
            (*players)[i].lookAtCards();
        if (points() == 11) {
            std::cout << "Dealer got Ace!" << std::endl;
        } else if (points() == 10) {
            std::cout << "Dealer got 10 points!" << std::endl;
        }
        addCard(closedCard);
        show();
        if (points() == 21) {
            std::cout << "Dealer has BlackJack!" << std::endl;
            for (int i = 0; i < players->size(); i++)
                if ((*players)[i].points() == 21)
                    (*players)[i].blackJack();
        } else {
            for (int i = 0; i < players->size(); i++)
                if ((*players)[i].points() == 21)
                    (*players)[i].blackJack();
                else
                    passMove(&(*players)[i]);
            if (not allPlayersBusted()) {
                while (points() < 17)
                    addCard(deck.giveCard());
                if (points() > 21)
                    bust();
            }
        }
    } else {
        for (int i = 0; i < players->size(); i++)
            if ((*players)[i].points() == 21)
                (*players)[i].blackJack();
            else
                passMove(&(*players)[i]);
        if (not allPlayersBusted()) {
            addCard(closedCard);
            while (points() < 17)
                addCard(deck.giveCard());
            if (points() > 21)
                bust();
        }
    }

    for (int i = 0; i < players->size(); i++)
        resolve(&(*players)[i]);
}

void Dealer::passMove(Player *player) {
    player->play();
    if (player->isBusted())
        player->lose();
}

void Dealer::resolve(Player *player) {
    if (not player->isBusted()) {
        if (isBusted())
            if (player->points() == 21)
                player->win1_5Bet();
            else
                player->win1_0Bet();
        else {
            show();
            if (player->points() < points())
                player->lose();
            else if (player->points() == points())
                player->draw();
            else if (player->points() == 21)
                player->win1_5Bet();
            else
                player->win1_0Bet();
        }
    }
}

void Dealer::show() {
    std::cout << "Dealer's hand: ";
    cards.show();
}

void Dealer::bust() {
    show();
    std::cout << "Dealer's busted!" << std::endl;
    busted = true;
}

bool Dealer::allPlayersBusted() {
    bool ok = false;
    for (int i = 0; i < players->size() and not ok; i++)
        ok = (*players)[i].isBusted();
    return ok;
}

