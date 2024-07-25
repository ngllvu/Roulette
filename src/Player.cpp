#include "Player.h"

Player::Player()
{
}

Player::Player(std::string name, double money)
{
    this->name = name;
    this->money = money;
}
Player::~Player()
{
}

void Player::setPlayer(std::string name, double money)
{
    this->name = name;
    this->money = money;
}
Player Player::getPlayer()
{
    return *this;
}
Player &Player::operator=(const Player &Player)
{

    this->name = Player.name;
    this->money = Player.money;
    return *this;
}

bool Player::operator==(const Player &Player)
{
    return (this->name == Player.name && this->money == Player.money);
}

bool Player::operator!=(const Player &Player)
{
    return !(*this == Player);
}