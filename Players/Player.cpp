#include "Player.h"

Player::Player() : _dealer(nullptr), _busted(false) {
    _cards = new Hand();
}

Player::~Player() {
    delete _cards;
}

Player::Player(Player&& player) {
    _dealer = player._dealer;
    _cards = player._cards;
    _busted = player._busted;

    player._dealer = nullptr;
    player._cards = nullptr;
    player._busted = false;
}

Player& Player::operator=(Player&& player) {
    if (this != &player) {
        _dealer = player._dealer;
        _cards = player._cards;
        _busted = player._busted;

        player._dealer = nullptr;
        player._cards = nullptr;
        player._busted = false;
    }
    return *this;
}

void Player::addDealer(Dealer *d) {
    _dealer = d;
}

void Player::addCard(Card card) {
    _cards->addCard(card);
}

void Player::play() {
    char c = 'h';
    while (c != 's' and points() < 21) {
        show();
        c = makeDecision();
        if (c == 'h')
            addCard(requestCard());
    }
    if (points() > 21)
        bust();
}

void Player::bust() {
    show();
    std::cout << "You're busted!" << std::endl;
    _busted = true;
}

int Player::points() const {
    return _cards->totalValue();
}

Card Player::requestCard() const {
    return _dealer->handOut();
}

char Player::makeDecision() const {
    char c;
    std::cout << "Your turn: ";
    std::cin >> c;
    return c;
}

bool Player::isBusted() const {
    return _busted;
}

void Player::blackJack() const {
    show();
    std::cout << "You've got BlackJack!" << std::endl;
}

void Player::lose() const {
    show();
    std::cout << "You lose" << std::endl;
}

void Player::draw() const {
    show();
    std::cout << "Draw" << std::endl;
}

void Player::win1_0Bet() const {
    show();
    std::cout << "You win 1" << std::endl;
}

void Player::win1_5Bet() const {
    show();
    std::cout << "You win 3/2" << std::endl;
}

void Player::lookAtCards() const {
    show();
}

void Player::show() const {
    std::cout << "Your hand: ";
    _cards->show();
    std::cout << " (" << points() << ")" << std::endl;
}

Dealer::Dealer(int numberDeck) : Player()
    , _players(nullptr)
    , _closedCard(nullptr)
    , _cardIsClosed(false)
    , _countDeck(numberDeck)
    , _deck(nullptr) {}

Dealer::~Dealer() {
    _players->clear();
    delete _closedCard;
    delete _deck;
}

Card Dealer::handOut() {
    return _deck->giveCard();
}

void Dealer::addPlayers(std::vector<Player> *players) {
    _players = players;
}

void Dealer::makeDeckPile() {
    _deck = new DeckPile(_countDeck);
}

void Dealer::handOutAll() {
    for (int i = 0; i < _players->size(); i++)
        (*_players)[i].addCard(handOut());
}

// TODO: TOO BIG FUNCTION
void Dealer::startRound() {
    std::cout << std::endl;

    if (_deck == nullptr or _deck->size() < (_players->size() + 1) * 15)
        makeDeckPile();

    handOutAll();
    addCard(handOut());
    handOutAll();
    _closedCard = new Card(handOut());
    _cardIsClosed = true;

    show();
    if (points() >= 10) {
        for (int i = 0; i < _players->size(); i++)
            (*_players)[i].lookAtCards();
        if (points() == 11) {
            std::cout << "Dealer got Ace!" << std::endl;
        } else if (points() == 10) {
            std::cout << "Dealer got 10!" << std::endl;
        }
        if (_closedCard->value() + points() == 21) {
            addCard(*_closedCard);
            _cardIsClosed = false;
            show();
            std::cout << "Dealer got BlackJack!" << std::endl;
            for (int i = 0; i < _players->size(); i++)
                if ((*_players)[i].points() == 21)
                    (*_players)[i].blackJack();
        } else {
            show();
            for (int i = 0; i < _players->size(); i++)
                if ((*_players)[i].points() == 21)
                    (*_players)[i].blackJack();
                else
                    passMove(&(*_players)[i]);
            if (not allPlayersBusted()) {
                addCard(*_closedCard);
                _cardIsClosed = false;
                show();
                while (points() < 17)
                    addCard(_deck->giveCard());
                if (points() > 21)
                    bust();
            }
        }
    } else {
        for (int i = 0; i < _players->size(); i++)
            if ((*_players)[i].points() == 21)
                (*_players)[i].blackJack();
            else
                passMove(&(*_players)[i]);
        if (not allPlayersBusted()) {
            addCard(*_closedCard);
            _cardIsClosed = false;
            show();
            while (points() < 17)
                addCard(_deck->giveCard());
            if (points() > 21)
                bust();
        }
    }

    for (int i = 0; i < _players->size(); i++)
        resolve(&(*_players)[i]);
}

void Dealer::bust() {
    show();
    std::cout << "Dealer's busted!" << std::endl;
    _busted = true;
}

bool Dealer::allPlayersBusted() const {
    bool ok = false;
    for (int i = 0; i < _players->size() and not ok; i++)
        ok = (*_players)[i].isBusted();
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

void Dealer::show() const {
    std::cout << "Dealer's hand: ";
    _cards->show();
    if (_cardIsClosed)
        std::cout << " ##";
    std::cout << " (" << points() << ")" << std::endl;
}