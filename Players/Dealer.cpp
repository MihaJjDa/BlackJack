/*
#include "Dealer.h"



Dealer::Dealer(int numberDeck) : IPlayer()
        , _players(nullptr)
        , _closedCard(nullptr)
        , _cardIsClosed(false)
        , _countDeck(numberDeck)
        , _deck(nullptr) {}

Dealer::~Dealer() {
    _players->clear();
    delete _closedCard;
    delete _deck;
}

Card Dealer::handOut() {
    return _deck->giveCard();
}

void Dealer::addPlayers(std::vector<Player> *players) {
    _players = players;
}

void Dealer::makeDeckPile() {
    _deck = new DeckPile(_countDeck);
}

void Dealer::handOutAll() {
    for (int i = 0; i < _players->size(); i++)
        (*_players)[i].addCard(handOut());
}

// TODO: TOO BIG FUNCTION
void Dealer::play() {
    std::cout << std::endl;

    if (_deck == nullptr or _deck->size() < (_players->size() + 1) * 15)
        makeDeckPile();

    handOutAll();
    addCard(handOut());
    handOutAll();
    _closedCard = new Card(handOut());
    _cardIsClosed = true;

    show();
    if (points() >= 10) {
        for (int i = 0; i < _players->size(); i++)
            (*_players)[i].lookAtCards();
        if (points() == 11) {
            std::cout << "Dealer got Ace!" << std::endl;
        } else if (points() == 10) {
            std::cout << "Dealer got 10!" << std::endl;
        }
        if (_closedCard->value() + points() == 21) {
            addCard(*_closedCard);
            _cardIsClosed = false;
            show();
            std::cout << "Dealer got BlackJack!" << std::endl;
            for (int i = 0; i < _players->size(); i++)
                if ((*_players)[i].points() == 21)
                    (*_players)[i].blackJack();
        } else {
            show();
            for (int i = 0; i < _players->size(); i++)
                if ((*_players)[i].points() == 21)
                    (*_players)[i].blackJack();
                else
                    passMove(&(*_players)[i]);
            if (not allPlayersBusted()) {
                addCard(*_closedCard);
                _cardIsClosed = false;
                show();
                while (points() < 17)
                    addCard(_deck->giveCard());
                if (points() > 21)
                    bust();
            }
        }
    } else {
        for (int i = 0; i < _players->size(); i++)
            if ((*_players)[i].points() == 21)
                (*_players)[i].blackJack();
            else
                passMove(&(*_players)[i]);
        if (not allPlayersBusted()) {
            addCard(*_closedCard);
            _cardIsClosed = false;
            show();
            while (points() < 17)
                addCard(_deck->giveCard());
            if (points() > 21)
                bust();
        }
    }

    for (int i = 0; i < _players->size(); i++)
        resolve(&(*_players)[i]);
}

void Dealer::bust() {
    show();
    std::cout << "Dealer's busted!" << std::endl;
    _busted = true;
}

bool Dealer::allPlayersBusted() const {
    bool ok = false;
    for (int i = 0; i < _players->size() and not ok; i++)
        ok = (*_players)[i].isBusted();
    return ok;
}

void Dealer::passMove(Player *player) const {
    player->play();
    if (player->points() == 21)
        player->blackJack();
    else if (player->isBusted())
        player->lose();
}

void Dealer::resolve(Player *player) const {
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

void Dealer::show() const {
    std::cout << "Dealer's hand: ";
    _cards->show();
    if (_cardIsClosed)
        std::cout << " ##";
    std::cout << " (" << points() << ")" << std::endl;
}
 */