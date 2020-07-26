#include "Card.h"



Card::Card(Ranks rank, Suits suit)
    : _rank(rank), _suit(suit) {}

void Card::show(char end) const {
    std::cout << *this << end;
}

int Card::value() const {
    int v;
    switch (_rank) {
        case Ranks::TWO:
            v = 2; break;
        case Ranks::THREE:
            v = 3; break;
        case Ranks::FOUR:
            v = 4; break;
        case Ranks::FIVE:
            v = 5; break;
        case Ranks::SIX:
            v = 6; break;
        case Ranks::SEVEN:
            v = 7; break;
        case Ranks::EIGHT:
            v = 8; break;
        case Ranks::NINE:
            v = 9; break;
        case Ranks::ACE:
            v = 11; break;
        default:
            v = 10; break;
    }
    return v;
}

std::ostream& operator<< (std::ostream &out, const Card card) {
    switch (card._rank) {
        case Ranks::TWO:
            out << "2"; break;
        case Ranks::THREE:
            out << "3"; break;
        case Ranks::FOUR:
            out << "4"; break;
        case Ranks::FIVE:
            out << "5"; break;
        case Ranks::SIX:
            out << "6"; break;
        case Ranks::SEVEN:
            out << "7"; break;
        case Ranks::EIGHT:
            out << "8"; break;
        case Ranks::NINE:
            out << "9"; break;
        case Ranks::TEN:
            out << "10"; break;
        case Ranks::JACK:
            out << "J"; break;
        case Ranks::QUEEN:
            out << "Q"; break;
        case Ranks::KING:
            out << "K"; break;
        case Ranks::ACE:
            out << "A"; break;
    }
    switch (card._suit) {
        case Suits::CLUBS:
            out << "C"; break;
        case Suits::DIAMONDS:
            out << "D"; break;
        case Suits::HEARTS:
            out << "H"; break;
        case Suits::SPADES:
            out << "S"; break;
    }
}

bool operator< (Card a, Card b) {
    return a._rank < b._rank or a._rank == b._rank and a._suit < b._suit;
}