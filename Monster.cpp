#include "Monster.h"
#include <iostream>

int Monster::get_hp() const
{
    return (this->hp);
}

int Monster::get_protection() const
{
    return (this->protection);
}

int Monster::get_strength () const
{
    return (this->strength);
}

void Monster::set_damage(int damage)
{
    this->hp -= damage;
}

void Monster::set_update_strength(int upd)
{
    this->update_of_damage = upd;
    this->strength += update_of_damage;
}

void Monster::set_start_properties()
{
    this->strength -= update_of_damage;
    this->update_of_damage = 0;
}

bool Monster::ALIVE()
{
    if (this->hp <= 0)
        alive = false;
    this->set_start_properties();
    return alive;
}

string Monster::get_name() const
{
    return this->name;
}


