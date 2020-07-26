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
    Card(Ranks rank, Suits suit);
    ~Card() = default;
    Card(const Card& game) = default;
    Card& operator=(const Card& game) = default;
    Card(Card&& game) = default;
    Card& operator=(Card&& game) = default;

    void show(char end = '\0') const;
    int value() const;
private:
    friend std::ostream& operator<<(std::ostream &out, Card card);
//protected:
    friend bool operator<(Card a, Card b);
};
