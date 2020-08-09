#include "Dealer.h"



Dealer::Dealer(int numberDeck)
        : _countDeck(numberDeck)
        , _deck(DeckPile(numberDeck))
        , _cardIsClosed(false) {}

Card Dealer::handOut() {
    return _deck.giveCard();
}

void Dealer::addPlayers(std::deque<IPlayer*> *players) {
    _players = players;
}

std::deque<IPlayer*> Dealer::playRound() {
    setRound();
    if (points() >= 10) {
        if (_closedCard.value() + points() == 21) {
            std::cout << std::endl;
            addClosedCard();
            show();
            std::cout << "Dealer has got BlackJack!" << std::endl << std::endl;
        } else {
            std::cout << "Dealer hasn't got BlackJack" << std::endl << std::endl;
            allPlay();
            play();
        }
    } else {
        std::cout << std::endl;
        allPlay();
        play();
    }
    allResolve();
    return outPlayers();
}

void Dealer::setRound() {
    makeDeckPile();
    setHand();
    allSetHand();
    allMakeBet();
    allHandOut();
    addOpenedCard();
    allHandOut();
    setClosedCard();
    show();
    allLookAtCards();
    if (points() == 11)
        std::cout << "Dealer has got Ace!" << std::endl;
    else if (points() == 10)
        std::cout << "Dealer has got 10 points!" << std::endl;
}

void Dealer::play() {
    if (allPlayersBusted()) {
        std::cout << "All players are busted!" << std::endl << std::endl;
    } else {
        addClosedCard();
        if (points() < 17)
            show();
        while (points() < 17)
            addOpenedCard();
        show();
        if (points() > 21) {
            std::cout << "Dealer's busted!" << std::endl;
        }
        std::cout << std::endl;
    }
}

void Dealer::makeDeckPile() {
    if (_deck.size() < (_players->size() + 1) * 15)
        _deck = DeckPile(_countDeck);
}

void Dealer::allSetHand() const {
    for (auto p = _players->begin(); p < _players->end(); p++)
        (*p)->setHand();
}

void Dealer::allMakeBet() const {
    for (auto p = _players->begin(); p < _players->end(); p++)
        (*p)->makeBet();
}

void Dealer::allHandOut() {
    for (auto p = _players->begin(); p < _players->end(); p++)
        (*p)->addCard(handOut());
}

void Dealer::allLookAtCards() const {
    for (auto p = _players->begin(); p < _players->end(); p++)
        (*p)->lookAtCards();
}

void Dealer::allPlay() const {
    for (auto p = _players->begin(); p < _players->end(); p++)
        (*p)->play();
}

void Dealer::allResolve() const {
    for (auto p = _players->begin(); p < _players->end(); p++)
        resolve(*p);
}

std::deque<IPlayer*> Dealer::outPlayers() const {
    std::deque<IPlayer*> outPlayers;
    for (auto p = _players->begin(); p < _players->end(); p++)
        if (not (*p)->gameIsOn())
            outPlayers.push_back(*p);
    return outPlayers;
}

void Dealer::addOpenedCard() {
    addCard(handOut());
}

void Dealer::setClosedCard() {
    _closedCard = handOut();
    _cardIsClosed = true;
}

void Dealer::addClosedCard() {
    addCard(_closedCard);
    _cardIsClosed = false;
}

bool Dealer::allPlayersBusted() const {
    bool ok = true;
    for (auto p = _players->begin(); ok and p < _players->end(); p++)
        ok = (*p)->isBusted();
    return ok;
}

void Dealer::resolve(IPlayer *player) const {
    player->lookAtCards();
    if (player->isBusted()) {
        player->lose();
    } else if (isBusted()) {
        if (player->points() == 21)
            player->win1_5Bet();
        else
            player->win1_0Bet();
    } else {
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

void Dealer::show() const {
    std::cout << "Dealer's hand: ";
    _cards.show();
    if (_cardIsClosed)
        std::cout << " ##";
    std::cout << " (" << points() << ")" << std::endl;
}