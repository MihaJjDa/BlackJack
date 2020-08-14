#include "IPlayer.h"



IPlayer::IPlayer(std::string name, Dealer *dealer, int initCash)
    : _name(name)
    , _dealer(dealer)
    , _cash(initCash)
    , _bet(0)
    , _doubled(false) {}

void IPlayer::makeBet() {
    std::cout << _name << "| Your cash: " << _cash << "; Your bet: ";
    _bet = bet();
}

void IPlayer::play() {
    char c = '\0';
    if (points() < 21) {
        bool turnIsOn = true, first = true;
        while (turnIsOn) {
            c = playTurn(first);
            if (first and c == 'd' and _bet * 2 <= _cash) {
                addCard(_dealer->handOut());
                _bet *= 2;
                turnIsOn = false;
            } else if (c == 'h') {
                addCard(_dealer->handOut());
                if (points() >= 21)
                    turnIsOn = false;
                else
                    first = false;
            } else if (c == 's') {
                turnIsOn = false;
            } else {
                std::cout << _name << "| Bad turn!" << std::endl;
            }
            std::cout << std::endl;
        }
    }
    if (c != 's')
        finishTurn();
}

void IPlayer::setTurn() const {
    std::cout << _name << "| Your cash: " << _cash << "; "
              << "Your bet: " << _bet << std::endl;
    std::cout << _name << "| ";
    _dealer->show();
    show();
}

char IPlayer::playTurn(bool first) {
    char c;
    setTurn();
    if (first and _bet * 2 > _cash)
        std::cout << _name << "| You can't double your bet!" << std::endl;
    std::cout << _name << "| Your turn ";
    if (first and _bet * 2 <= _cash)
        std::cout << "(d - double, h - hit, s - stand): ";
    else
        std::cout << "(h - hit, s - stand): ";
    return turn();
}

void IPlayer::finishTurn() const {
    setTurn();
    if (points() == 21)
        std::cout << _name << "| You've got BlackJack!" << std::endl;
    else if (points() > 21)
        std::cout << _name << "| You're busted!" << std::endl;
    std::cout << std::endl;
}

void IPlayer::lose() {
    std::cout << _name << "| You lose 1 bet: " << _bet << std::endl;
    _cash -= _bet;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void IPlayer::win1_0Bet() {
    std::cout << _name << "| You win 1 bet: " << _bet << std::endl;
    _cash += _bet;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void IPlayer::win1_5Bet() {
    std::cout << _name << "| You win 3/2 bet: " << _bet * 3/2 << std::endl;
    _cash += _bet * 3/2;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void IPlayer::draw() const {
    std::cout << _name << "| Draw" << std::endl;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

bool IPlayer::gameIsOn() const {
    bool ok;
    if (_cash > 0) {
        ok = cont();
    } else {
        std::cout << _name << "| Your cash is empty!" << std::endl;
        ok = false;
    }
    return ok;
}

void IPlayer::lookAtCards() const {
    show();
}

void IPlayer::show() const {
    std::cout << _name << "| Your hand: ";
    _cards.show();
    std::cout << " (" << points() << ")" << std::endl;
}