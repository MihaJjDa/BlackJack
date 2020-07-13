#include <iostream>

enum Ranks {
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

enum Suits {
    CLUBS,    // трефы
    DIAMONDS, // бубны
    HEARTS,   // червы
    SPADES    // пики
};

struct Card {
    Ranks rank;
    Suits suit;

    Card();
    Card(Ranks newRank, Suits newSuit);
    void show(char end = '\0');
    int value() const;
private:
    friend std::ostream& operator<< (std::ostream &out, Card card);
protected:
    friend bool operator< (Card a, Card b);
};
