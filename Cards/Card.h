#pragma once

#include <iostream>

enum class Ranks : uint8_t {
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE
};

enum class Suits : uint8_t {
    CLUBS,    // трефы
    DIAMONDS, // бубны
    HEARTS,   // червы
    SPADES    // пики
};

class Card {
    Ranks _rank;
    Suits _suit;
public:
    Card(Ranks rank = Ranks::JACK, Suits suit = Suits::SPADES);

    int value() const;
    void show(char end = '\0') const;
private:
    friend std::ostream& operator<<(std::ostream &out, Card card);
    friend bool operator<(Card a, Card b);
};
