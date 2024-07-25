#pragma once
#include "stdc++.h"
#include "ListPlayer.h"

class Player
{
private:
    std::string name;
    double money;
    friend class ListPlayer;
    friend class Roulette;

public:
    Player();
    Player(std::string name, double money);
    ~Player();
    void setPlayer(std::string name, double money);
    Player getPlayer();
    Player &operator=(const Player &player);
    bool operator==(const Player &player);
    bool operator!=(const Player &player);
};