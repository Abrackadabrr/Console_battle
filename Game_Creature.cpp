#include "Game_Creature.h"

Game_Creature::Game_Creature()
{
    this->alive = true;
    this->update_of_protection = 0;
}

int Game_Creature:: get_hp() const
{
    return (this->hp);
}

int Game_Creature::get_protection() const
{
return (this->protection);
}

int Game_Creature::get_strength () const
{
return (this->strength);
}

void Game_Creature::set_damage(int damage)
{
    this->hp -= damage;
}

void Game_Creature::set_update_protection(int upd)
{
    this->update_of_protection = upd;
    this->protection += update_of_protection;
}

void Game_Creature::set_start_properties()
{
    this->protection -= update_of_protection;
    this->update_of_protection = 0;
}


bool Game_Creature::check_alive()
{
    if (this->hp <= 0)
        alive = false;
    this->set_start_properties();
    return alive;
}

string Game_Creature::get_name() const
{
    return this->name;
}
