#include "Player.h"



Player::Player(std::string name, Dealer *dealer, int initCash)
    : _name(name)
    , _dealer(dealer)
    , _cash(initCash)
    , _bet(0)
    , _doubled(false) {}

void Player::makeBet() {
    std::cout << _name << "| Your cash: " << _cash << "; Your bet: ";
    do {
        std::cin >> _bet;
        if (_bet > _cash) {
            std::cout << _name << "| Bad bet!" << std::endl;
            std::cout << _name << "| Your cash: " << _cash << "; Your bet: ";
        }
    } while (_bet > _cash);
}

void Player::play() {
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

void Player::setTurn() const {
    std::cout << _name << "| Your cash: " << _cash << "; "
              << "Your bet: " << _bet << std::endl;
    std::cout << _name << "| ";
    _dealer->show();
    show();
}

char Player::playTurn(bool first) {
    char c;
    setTurn();
    if (first and _bet * 2 > _cash)
        std::cout << _name << "| You can't double your bet!" << std::endl;
    std::cout << _name << "| Your turn ";
    if (first and _bet * 2 <= _cash)
        std::cout << "(d - double, h - hit, s - stand): ";
    else
        std::cout << "(h - hit, s - stand): ";
    std::cin >> c;
    return c;
}

void Player::finishTurn() const {
    setTurn();
    if (points() == 21)
        std::cout << _name << "| You've got BlackJack!" << std::endl;
    else if (points() > 21)
        std::cout << _name << "| You're busted!" << std::endl;
    std::cout << std::endl;
}

void Player::lose() {
    std::cout << _name << "| You lose 1 bet: " << _bet << std::endl;
    _cash -= _bet;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void Player::win1_0Bet() {
    std::cout << _name << "| You win 1 bet: " << _bet << std::endl;
    _cash += _bet;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void Player::win1_5Bet() {
    std::cout << _name << "| You win 3/2 bet: " << _bet * 3/2 << std::endl;
    _cash += _bet * 3/2;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

void Player::draw() const {
    std::cout << _name << "| Draw" << std::endl;
    std::cout << _name << "| Your cash: " << _cash << std::endl << std::endl;
}

bool Player::gameIsOn() const {
    bool ok;
    if (_cash > 0) {
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
    } else {
        std::cout << _name << "| Your cash is empty!" << std::endl;
        ok = false;
    }
    return ok;
}

void Player::lookAtCards() const {
    show();
}

void Player::show() const {
    std::cout << _name << "| Your hand: ";
    _cards.show();
    std::cout << " (" << points() << ")" << std::endl;
}