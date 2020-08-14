#include "LocalPlayer.h"



LocalPlayer::LocalPlayer(std::string name, Dealer *dealer, int initCash)
        : IPlayer(name, dealer, initCash) {}

int LocalPlayer::bet() const {
    int b;
    do {
        std::cin >> b;
        if (_bet > _cash) {
            std::cout << _name << "| Bad bet!" << std::endl;
            std::cout << _name << "| Your cash: " << _cash << "; Your bet: ";
        }
    } while (_bet > _cash);
    return b;
}

char LocalPlayer::turn() const {

    char c;
    std::cin >> c;
    return c;
}

bool LocalPlayer::cont() const {
    bool ok;
    char c;
    do {
        std::cout << _name << "| Would you continue (y/n): ";
        std::cin >> c;
        if (c == 'y')
            ok = true;
        else if (c == 'n')
            ok = false;
        else
            std::cout << _name << "| Bad turn!" << std::endl;
    } while (c != 'y' and c != 'n');
    return ok;
}