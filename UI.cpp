#include "UI.h"
#include <cstdlib>
#include <iostream>
#include "warrior.h"
#include "dragon.h"
#include "help_classes.h"
#include_next "troll.h"
UI::UI()
{
    monster = nullptr;
    Player = nullptr;
    finished = false;
}

UI::~UI()
{
    delete monster;
    delete Player;
}

bool UI::is_finished()
{
    return this->finished;
}

Player* UI::create_player(string s)
{
    if (s == "1")
    {
        this->Player = new warrior("Женя");
        return this->Player;
    }
}

monster* UI::create_monster()
{
    this->monster = new troll;
    return this->monster;
}

int UI::d3() {
    return (rand()%3 + 1);
}

int UI::d20()
{
    return (rand()%20 + 1);
}

DATA_BOX* UI::read_player_massage(string str)
{
    DATA_BOX* data = nullptr;
    if (str == "Защита" || str == "защита")
    {
        int q = this->d3();
        Player->set_update_protection(q);
        data = new DATA_BOX(q, Player->get_protection(), 12);
    }
    if (str == "Атака" || str == "атака")
    {
        int a = this->d20();
        if (a >= monster->get_protection())
        {

            if (this->d20() < 4 && Player->warr)
            {
                monster->set_damage(2 * Player->get_strength());
                data = new DATA_BOX(a,2* Player->get_strength(),13);
            }
            else {
                monster->set_damage(Player->get_strength());
                data = new DATA_BOX(a, Player->get_strength(), 11);
            }
        }
        else
            data = new DATA_BOX(a,0,10);
    }
    return data;
}

DATA_BOX* UI::monster_attack()
{
    DATA_BOX* data = nullptr;
    int b = this->d20();
    if (b >= Player->get_protection())
    {
        Player->set_damage(monster->get_strength());
        data = new DATA_BOX(b, monster->get_strength(), 21);
    }
    else
    {
        data = new DATA_BOX(b, 0, 20);
    }
    return data;
}

DATA_BOX* UI::update()

{
    DATA_BOX* data = nullptr;
    if (!Player->ALIVE() && monster->ALIVE())
    {
        finished = true;
        data = new DATA_BOX(0,0, 30);
    }
    if (!monster->ALIVE() && Player->ALIVE())
    {
        finished = true;
        data = new DATA_BOX(0,0, 31);
    }
    if (!monster->ALIVE() && !Player->ALIVE())
    {
        data = new DATA_BOX(0,0, 32);
        finished = true;
    }
    return data;
}