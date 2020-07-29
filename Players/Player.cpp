#include "Player.h"



Player::Player(std::string name, Dealer *dealer, int initCash)
    : _name(name)
    , _dealer(dealer)
    , _cash(initCash)
    , _bet(0) {}

void Player::makeBet() {
    std::cout << _name << ": your cash: " << _cash << ", your bet: ";
    do {
        std::cin >> _bet;
        if (_bet > _cash) {
            std::cout << _name << ": bad bet!" << std::endl;
            std::cout << _name << ": your cash: " << _cash << ", your bet: ";
        }
    } while (_bet > _cash);
}

void Player::doubleBet() {
    if (_bet * 2 > _cash) {
        std::cout << _name << ": you can't double your bet!" << std::endl;
    } else {
        char c;
        do {
            std::cout << _name << ": would you double your bet (y/n): ";
            std::cin >> c;
            if (c == 'y')
                _bet *= 2;
            else if (c != 'n')
                std::cout << _name << ": bad turn!" << std::endl;
        } while (c != 'y' and c != 'n');
    }
}

void Player::play() {
    char c = 'h';
    while (c != 's' and points() < 21) {
        std::cout << _name << ": your cash: " << _cash
                  << ", your bet: " << _bet << std::endl;
        _dealer->show();
        show();
        std::cout << _name << ": your turn (h - hit, s - stand): ";
        std::cin >> c;
        if (c == 'h')
            addCard(_dealer->handOut());
        else if (c != 's')
            std::cout << std::endl << _name << ": bad turn!" << std::endl;
        if (points() <= 21)
            std::cout << std::endl;
    }
    if (points() == 21) {
        show();
        std::cout << _name << ": you've got BlackJack!" << std::endl
                                                        << std::endl;
    } else if (points() > 21) {
        std::cout << std::endl;
        show();
        std::cout << _name << ": you're busted!" << std::endl << std::endl;
    }
}

void Player::lose() {
    std::cout << _name << ": you lose 1 bet: " << _bet << std::endl;
    _cash -= _bet;
    std::cout << _name << ": your cash: " << _cash << std::endl << std::endl;
}

void Player::win1_0Bet() {
    std::cout << _name << ": you win 1 bet: " << _bet << std::endl;
    _cash += _bet;
    std::cout << _name << ": your cash: " << _cash << std::endl << std::endl;
}

void Player::win1_5Bet() {
    std::cout << _name << ": you win 3/2 bet: " << _bet * 3/2 << std::endl;
    _cash += _bet * 3/2;
    std::cout << _name << ": your cash: " << _cash << std::endl << std::endl;
}

void Player::draw() const {
    std::cout << _name << ": draw" << std::endl;
    std::cout << _name << ": your cash: " << _cash << std::endl << std::endl;
}

bool Player::gameIsOn() const {
    bool ok;
    if (_cash > 0) {
        char c;
        do {
            std::cout << _name << ": would you continue (y/n): ";
            std::cin >> c;
            if (c == 'y')
                ok = true;
            else if (c == 'n')
                ok = false;
            else
                std::cout << _name << ": bad turn!" << std::endl;
        } while (c != 'y' and c != 'n');
    } else {
        std::cout << _name << ": your cash is empty!" << std::endl;
        ok = false;
    }
    return ok;
}

void Player::lookAtCards() const {
    show();
}

void Player::show() const {
    std::cout << _name << ": your hand: ";
    _cards.show();
    std::cout << " (" << points() << ")" << std::endl;
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

bool Dealer::playRound() {
    setRound();
    std::cout << std::endl;
    if (points() >= 10) {
        if (_closedCard.value() + points() == 21) {
            addClosedCard();
            show();
            std::cout << "Dealer has got BlackJack!" << std::endl << std::endl;
        } else {
            std::cout << "Dealer hasn't got BlackJack" << std::endl;
            allPlay();
            play();
        }
    } else {
        allPlay();
        play();
    }
    allResolve();
    return gameIsOn();
}

void Dealer::setRound() {
    makeDeckPile();
    setHand();
    allSetHand();
    allMakeBet();
    allHandOut();
    addOpenedCard();
    allHandOut();
    setClosedCard();
    show();
    allLookAtCards();
    if (points() == 11)
        std::cout << "Dealer has got Ace!" << std::endl;
    else if (points() == 10)
        std::cout << "Dealer has got 10 points!" << std::endl;
    allDoubleBet();
}

void Dealer::play() {
    if (allPlayersBusted()) {
        std::cout << "All players are busted!" << std::endl << std::endl;
    } else {
        addClosedCard();
        if (points() < 17)
            show();
        while (points() < 17)
            addOpenedCard();
        show();
        if (points() > 21) {
            std::cout << "Dealer's busted!" << std::endl;
        }
        std::cout << std::endl;
    }
}

void Dealer::makeDeckPile() {
    if (_deck.size() < (_players.size() + 1) * 15)
        _deck = DeckPile(_countDeck);
}

void Dealer::allSetHand() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->setHand();
}

void Dealer::allMakeBet() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->makeBet();
}

void Dealer::allHandOut() {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->addCard(handOut());
}

void Dealer::allLookAtCards() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->lookAtCards();
}

void Dealer::allDoubleBet() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->doubleBet();
}

void Dealer::allPlay() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        (*p)->play();
}

void Dealer::allResolve() const {
    for (auto p = _players.begin(); p < _players.end(); p++)
        resolve(*p);
}

bool Dealer::gameIsOn() const {
    bool ok = true;
    for (auto p = _players.begin(); p < _players.end(); p++)
        ok = ok and (*p)->gameIsOn();
    return ok;
}

void Dealer::addOpenedCard() {
    addCard(handOut());
}

void Dealer::setClosedCard() {
    _closedCard = handOut();
    _cardIsClosed = true;
}

void Dealer::addClosedCard() {
    addCard(_closedCard);
    _cardIsClosed = false;
}

bool Dealer::allPlayersBusted() const {
    bool ok = true;
    for (auto p = _players.begin(); ok and p < _players.end(); p++)
        ok = (*p)->isBusted();
    return ok;
}

void Dealer::resolve(Player *player) const {
    player->lookAtCards();
    if (player->isBusted()) {
        player->lose();
    } else if (isBusted()) {
        if (player->points() == 21)
            player->win1_5Bet();
        else
            player->win1_0Bet();
    } else {
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

void Dealer::show() const {
    std::cout << "Dealer's hand: ";
    _cards.show();
    if (_cardIsClosed)
        std::cout << " ##";
    std::cout << " (" << points() << ")" << std::endl;
}