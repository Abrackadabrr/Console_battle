#include "PLayer.h"

Player::Player() {}

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

void Player::update_protection(int upd)
{
    this->update_of_protection = upd;
    this->protection += update_of_protection;
}

void Player::set_start_properties()
{
    this->protection -= update_of_protection;
    this->update_of_protection = 0;
}


bool Player::check_alive()
{
    if (this->hp < 0) alive == false;
    this->set_start_properties();
    return alive;
}

