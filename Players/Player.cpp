#include "Player.h"



Player::Player(Dealer *dealer, int initCash)
    : _dealer(dealer)
    , _cash(initCash)
    , _bet(0) {}

void Player::makeBet() {
    std::cout << "Your cash: " << _cash << ", your bet: ";
    do {
        std::cin >> _bet;
        if (_bet > _cash) {
            std::cout << "Bad bet!" << std::endl;
            std::cout << "Your cash: " << _cash << ", your bet: ";
        }
    } while (_bet > _cash);
}

void Player::doubleBet() {
    std::cout << "Your cash: " << _cash
              << ", your bet: " << _bet << std::endl;
    if (_bet * 2 > _cash)
        std::cout << "You can't double your bet!" << std::endl;
    else {
        char c;
        do {
            std::cout << "Would you double your bet (y/n): ";
            std::cin >> c;
            if (c == 'y')
                _bet *= 2;
            else if (c != 'n')
                std::cout << "Bad turn!" << std::endl;
            std::cout << "Your cash: " << _cash
                      << ", your bet: " << _bet << std::endl;
        } while (c != 'y' and c != 'n');
    }
}

void Player::play() {
    char c = 'h';
    while (c != 's' and points() < 21) {
        show();
        c = makeDecision();
        if (c == 'h')
            addCard(requestCard());
        else if (c != 's')
            std::cout << "Bad turn!\n";
    }
    if (points() > 21)
        bust();
}

void Player::lose() {
    show();
    std::cout << "You lose 1 bet: " << _bet << std::endl;
    _cash -= _bet;
    std::cout << "Your cash: " << _cash << std::endl;
}

void Player::win1_0Bet() {
    show();
    std::cout << "You win 1 bet: " << _bet << std::endl;
    _cash += _bet;
    std::cout << "Your cash: " << _cash << std::endl;
}

void Player::win1_5Bet() {
    show();
    std::cout << "You win 3/2 bet: " << _bet * 3/2 << std::endl;
    _cash += _bet * 3/2;
    std::cout << "Your cash: " << _cash << std::endl;
}

void Player::blackJack() const {
    show();
    std::cout << "You've got BlackJack!" << std::endl;
}

void Player::draw() const {
    show();
    std::cout << "Draw" << std::endl;
    std::cout << "Your cash: " << _cash << std::endl;
}

void Player::lookAtCards() const {
    show();
}

void Player::bust() {
    show();
    std::cout << "You're busted!" << std::endl;
}

bool Player::gameIsOn() const {
    if (_cash > 0) {
        bool ok;
        char c;
        do {
            std::cout << "Would you continue (y/n): ";
            std::cin >> c;
            if (c == 'y')
                ok = true;
            else if (c == 'n')
                ok = false;
            else
                std::cout << "Bad turn!" << std::endl;
        } while (c != 'y' and c != 'n');
        return ok;
    } else {
        std::cout << "Your cash is empty!" << std::endl;
        return false;
    }
}

void Player::show() const {
    std::cout << "Your hand: ";
    _cards.show();
    std::cout << " (" << points() << ")" << std::endl;
}

Card Player::requestCard() const {
    return _dealer->handOut();
}

char Player::makeDecision() const {
    char c;
    std::cout << "Your turn (h - hit, s - stand): ";
    std::cin >> c;
    return c;
}



Dealer::Dealer(int numberDeck)
    : _countDeck(numberDeck)
    , _deck(DeckPile(numberDeck))
    , _cardIsClosed(false) {}

Card Dealer::handOut() {
    return _deck.giveCard();
}

void Dealer::addPlayers(std::vector<Player> *players) {
    _players.clear();
    for (auto p = players->begin(); p < players->end(); p++)
        _players.push_back(&(*p));
}

void Dealer::makeDeckPile() {
    _deck = DeckPile(_countDeck);
}

void Dealer::handOutAll() {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->addCard(handOut());
}

// TODO: UNREADABLE FUNCTION
bool Dealer::play() {
    if (_deck.size() < (_players.size() + 1) * 15)
        makeDeckPile();

    setHand();
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->setHand();

    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->makeBet();

    handOutAll();
    addCard(handOut());
    handOutAll();
    _closedCard = handOut();
    _cardIsClosed = true;

    show();
    if (points() == 11) {
        std::cout << "Dealer has got Ace!" << std::endl;
    } else if (points() == 10) {
        std::cout << "Dealer has got 10!" << std::endl;
    }
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->lookAtCards();

    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->doubleBet();


    if (points() >= 10) {
        if (_closedCard.value() + points() == 21) {
            addCard(_closedCard);
            _cardIsClosed = false;
            show();
            std::cout << "Dealer has got BlackJack!" << std::endl;
            for (auto p = _players.begin(); p < _players.end(); p++)
                if ((*p)->points() == 21)
                    (*p)->blackJack();
        } else {
            show();
            std::cout << "Dealer hasn't got BlackJack" << std::endl;
            for (auto p = _players.begin(); p < _players.end(); p++)
                if ((*p)->points() == 21)
                    (*p)->blackJack();
                else
                    passMove(*p);
            if (not allPlayersBusted()) {
                addCard(_closedCard);
                _cardIsClosed = false;
                show();
                while (points() < 17)
                    addCard(_deck.giveCard());
                if (points() > 21)
                    bust();
            }
        }
    } else {
        show();
        for (auto p = _players.begin(); p < _players.end(); p++)
            if ((*p)->points() == 21)
                (*p)->blackJack();
            else
                passMove(*p);
        if (not allPlayersBusted()) {
            addCard(_closedCard);
            _cardIsClosed = false;
            if (points() < 17)
                show();
            while (points() < 17)
                addCard(_deck.giveCard());
            if (points() > 21)
                bust();
        }
    }

    for (auto p = _players.begin(); p < _players.end(); p++)
        resolve(*p);

    return gameIsOn();
}

bool Dealer::allPlayersBusted() const {
    bool ok = false;
    for (auto p = _players.begin(); p < _players.end(); p++)
        ok = (*p)->isBusted();
    return ok;
}

bool Dealer::gameIsOn() const {
    bool ok = true;
    for (auto p = _players.begin(); p < _players.end(); p++)
        ok = ok and (*p)->gameIsOn();
    return ok;
}

void Dealer::passMove(Player *player) const {
    player->play();
    if (player->points() == 21)
        player->blackJack();
    else if (player->isBusted())
        player->lose();
}

void Dealer::resolve(Player *player) const {
    if (not player->isBusted()) {
        if (isBusted())
            if (player->points() == 21)
                player->win1_5Bet();
            else
                player->win1_0Bet();
        else {
            show();
            if (player->points() < points())
                player->lose();
            else if (player->points() == points())
                player->draw();
            else if (player->points() == 21)
                player->win1_5Bet();
            else
                player->win1_0Bet();
        }
    }
}

void Dealer::bust() {
    show();
    std::cout << "Dealer's busted!" << std::endl;
}

void Dealer::show() const {
    std::cout << "Dealer's hand: ";
    _cards.show();
    if (_cardIsClosed)
        std::cout << " ##";
    std::cout << " (" << points() << ")" << std::endl;
}