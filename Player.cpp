#include "Player.h"
#include <iostream>
using namespace std;
Player::Player(string name)
{
    this->alive = true;
    this->update_of_protection = 0;
    this->name = name;
    cout << "Your Player " << this->get_name() << " is created"<< endl;
    hp = 1000;
    protection = 100;
    update_of_protection = 30;
    strength = 100;
}

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

void Player::set_update_protection(int upd)
{
    this->update_of_protection = upd;
    this->protection += update_of_protection;
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

