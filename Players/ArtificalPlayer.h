#pragma once

#include <string>

#include "IPlayer.h"
#include "Dealer.h"

// TODO: TESTS IN ASSERTS FOR EVERY METHOD

class ArtificalPlayer : public IPlayer {
public:
    ArtificalPlayer(std::string name, Dealer *dealer = nullptr, int initCash = 100);

private:
    int bet() const override;
    char turn() const override;
    bool cont() const override;
};