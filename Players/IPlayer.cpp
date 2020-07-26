#include "IPlayer.h"



IPlayer::IPlayer() : _busted(false) {
    _cards = new Hand();
}

IPlayer::~IPlayer() {
    delete _cards;
}

void IPlayer::addCard(Card card) {
    _cards->addCard(card);
}

int IPlayer::points() const {
    return _cards->totalValue();
}

bool IPlayer::isBusted() const {
    return _busted;
}