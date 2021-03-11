#include "GLogic.h"
#include <cstdlib>
#include "warrior.h"
#include "dragon.h"
#include "help_classes.h"
#include_next "troll.h"
GLogic::GLogic()
{
    monster = nullptr;
    Player = nullptr;
    finished = false;
}

GLogic::~GLogic()
{
    delete monster;
    delete Player;
}

bool GLogic::is_finished()
{
    return this->finished;
}

Player* GLogic::create_player(string s)
{
    if (s == "1")
    {
        this->Player = new warrior("Warrior");
        return this->Player;
    }
}

monster* GLogic::create_monster()
{
    if (d20() > 10)
        this->monster = new troll;
    else
        this->monster = new dragon;
    return this->monster;
}

int GLogic::d3() {
    return (rand()%3 + 1);
}

int GLogic::d20()
{
    return (rand()%20 + 1);
}

DATA_BOX* GLogic::read_player_massage(string str)
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

            if (this->d20() < 4 && Player->type == "warrior")
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

DATA_BOX* GLogic::monster_attack()
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

DATA_BOX* GLogic::update()

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