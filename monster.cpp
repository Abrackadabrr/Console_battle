#include "monster.h"
#include <iostream>

monster::monster()
{
    this->alive = true;
    this->update_of_damage = 0;
    this->name = "LABA";
    cout << "Monster "<< this->get_name()<< " is created" << endl;
    hp = 100;
    protection = 10;
    update_of_damage = 3;
    strength = 13;
}

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

bool monster::check_alive()
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


