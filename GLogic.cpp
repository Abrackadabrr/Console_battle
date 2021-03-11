#include "GLogic.h"
#include <cstdlib>
#include "warrior.h"
#include "dragon.h"
#include "help_classes.h"
#include "troll.h"
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
    return nullptr;
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

DATA_BOX* GLogic::read_player_massage(string massage)
{
    DATA_BOX* data = nullptr;
    if (massage == "Защита" || massage == "защита")
    {
        data = Player->set_update_protection();
    }
    if (massage == "Атака" || massage == "атака")
    {
        data = Player->attack(this->monster);
    }
    return data;
}

DATA_BOX* GLogic::monster_step()
{
    DATA_BOX* data = nullptr;
    monster->attack(this->Player);
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