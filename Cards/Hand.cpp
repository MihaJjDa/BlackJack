#include <algorithm>

#include "Hand.h"



Hand::Hand() : _cards(std::vector<Card>()) {}

Hand::~Hand() {
    _cards.clear();
};

void Hand::addCard(Card card) {
    if (_cards.empty()) {
        _cards.push_back(card);
    } else {
        auto it = _cards.begin();
        while (*it < card and it != _cards.end())
            it += 1;
        _cards.insert(it, card);
    }
}

bool Hand::empty() const {
    return _cards.empty();
}

int Hand::totalValue() const {
    int sum = 0;
    int countAces = 0;
    for (auto card : _cards) {
        sum += card.value();
        if (card.value() == 11)
            countAces += 1;
    }
    while (sum > 21 and countAces > 0) {
        sum -= 10;
        countAces -= 1;
    }
    return sum;
};

void Hand::show() const {
    if (not _cards.empty()) {
        for (auto it = _cards.begin(); it < _cards.end() - 1; it++)
            it->show(' ');
        _cards.back().show();
    }
}
