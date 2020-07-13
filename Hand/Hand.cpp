#include <algorithm>

#include "Hand.h"



Hand::Hand() = default;

Hand::~Hand() {
    cards.clear();
};

void Hand::addCard(Card card) {
    cards.push_back(card);
    std::sort(cards.begin(), cards.end()); // TODO: DELETE SORT
}

int Hand::totalValue() {
    int sum = 0;
    int countAces = 0;

    for (auto card : cards) {
        sum += card.value();
        if (card.rank == ACE)
            countAces += 1;
    }

    while (sum > 21 and countAces > 0) {
        sum -= 10;
        countAces -= 1;
    }

    return sum;
};

bool Hand::empty() {
    return cards.empty();
}

void Hand::show() {
    for (auto card : cards)
        card.show(' '); // TODO: DELETE LAST SPACE
    std::cout << std::endl;
}
