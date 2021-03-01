#include "Player.h"
#include <iostream>
Player::Player(string name)
{
    this->name = name;
    std::cout << "Your Player ", this->get_name(), " is created" << std::endl;
    hp = 1000;
    protection = 100;
    update_of_protection = 30;
    strength = 100;
}