#include "ArtificalPlayer.h"



ArtificalPlayer::ArtificalPlayer(std::string name, Dealer *dealer, int initCash)
    : Player(name, dealer, initCash) {}

int ArtificalPlayer::bet() const {
    int b;
    if (_cash <= 2)
        b = 2;
    else
        b = _cash / 3;
    std::cout << b << std::endl;
    return b;
}

char ArtificalPlayer::turn() const {
    char c;
    if (points() < 17)
        c = 'h';
    else
        c = 's';
    std::cout << c << std::endl;
    return c;
}

bool ArtificalPlayer::cont() const {
    std::cout << _name << "| Would you continue (y/n): ";
    std::cout << 'y' << std::endl;
    return true;
}