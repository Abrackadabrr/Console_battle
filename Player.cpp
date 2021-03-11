#include "Player.h"
#include <iostream>
using namespace std;

Player::Player()
{
    this->amount_of_actions = 1;
}

int Player::get_amount_of_actions() const
{return this->amount_of_actions;}

int Player:: get_hp() const
{
    return (this->hp);
}

int Player::get_protection() const
{
    return (this->protection);
}

int Player::get_strength () const
{
    return (this->strength);
}

void Player::set_damage(int damage)
{
    this->hp -= damage;
}

DATA_BOX* Player::set_update_protection()
{
    DATA_BOX* data;
    int upd = this->d3();
    this->update_of_protection = upd;
    this->protection += update_of_protection;
    data = new DATA_BOX(upd, this->get_protection(), 10002);
    return data;
}

void Player::set_start_properties()
{
    this->protection -= update_of_protection;
    this->update_of_protection = 0;
}

bool Player::ALIVE()
{
    if (this->hp <= 0)
        this->alive = false;
    this->set_start_properties();
    return this->alive;
}

string Player::get_name() const
{
    return this->name;
}

int Player::d3() {
    return (rand()%3 + 1);
}

int Player::d20() {
    return (rand()%20 + 1);
}