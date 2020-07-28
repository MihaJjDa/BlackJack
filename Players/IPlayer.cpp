#include "IPlayer.h"



void IPlayer::addCard(Card card) {
    _cards.addCard(card);
}

int IPlayer::points() const {
    return _cards.totalValue();
}

bool IPlayer::isBusted() const {
    return points() > 21;
}