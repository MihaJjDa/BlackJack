#include "IHolder.h"



void IHolder::addCard(Card card) {
    _cards.addCard(card);
}

void IHolder::setHand() {
    _cards = Hand();
}

int IHolder::points() const {
    return _cards.totalValue();
}

bool IHolder::isBusted() const {
    return points() > 21;
}


