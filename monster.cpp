#include "monster.h"
#include <iostream>

int monster::get_hp() const
{
    return (this->hp);
}

int monster::get_protection() const
{
    return (this->protection);
}

int monster::get_strength () const
{
    return (this->strength);
}

void monster::set_damage(int damage)
{
    this->hp -= damage;
}

void monster::set_update_strength(int upd)
{
    this->update_of_damage = upd;
    this->strength += update_of_damage;
}

void monster::set_start_properties()
{
    this->strength -= update_of_damage;
    this->update_of_damage = 0;
}

bool monster::ALIVE()
{
    if (this->hp <= 0)
        alive = false;
    this->set_start_properties();
    return alive;
}

string monster::get_name() const
{
    return this->name;
}


