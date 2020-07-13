#include "Card.h"

//TODO: DELETE DEFAULT CONSTRUCTOR BECAUSE OF DEALER
Card::Card() {
    rank = JACK;
    suit = SPADES;
}

Card::Card(Ranks newRank, Suits newSuit) {
    rank = newRank;
    suit = newSuit;
}

void Card::show(char end) {
    std::cout << *this << end;
}

int Card::value() const {
    int v;
    switch (rank) {
        case TWO:
            v = 2; break;
        case THREE:
            v = 3; break;
        case FOUR:
            v = 4; break;
        case FIVE:
            v = 5; break;
        case SIX:
            v = 6; break;
        case SEVEN:
            v = 7; break;
        case EIGHT:
            v = 8; break;
        case NINE:
            v = 9; break;
        case ACE:
            v = 11; break;
        default:
            v = 10; break;
    }
    return v;
}

std::ostream& operator<< (std::ostream &out, const Card card) {
    switch (card.rank) {
        case TWO:
            out << "2"; break;
        case THREE:
            out << "3"; break;
        case FOUR:
            out << "4"; break;
        case FIVE:
            out << "5"; break;
        case SIX:
            out << "6"; break;
        case SEVEN:
            out << "7"; break;
        case EIGHT:
            out << "8"; break;
        case NINE:
            out << "9"; break;
        case TEN:
            out << "T"; break;
        case JACK:
            out << "J"; break;
        case QUEEN:
            out << "Q"; break;
        case KING:
            out << "K"; break;
        case ACE:
            out << "A"; break;
    }
    switch (card.suit) {
        case CLUBS:
            out << "C"; break;
        case DIAMONDS:
            out << "D"; break;
        case HEARTS:
            out << "H"; break;
        case SPADES:
            out << "S"; break;
    }
};

bool operator< (Card a, Card b) {
    return a.rank < b.rank or a.rank == b.rank and a.suit < b.suit;
};