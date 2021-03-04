#include "UI.h"
#include <cstdlib>
#include <iostream>
#include "warrior.h"
#include "dragon.h"

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
    this->monster = new dragon;
    return this->monster;
}

int UI::d3() {
    return (rand()%3 + 1);
}

int UI::d20()
{
    return (rand()%20 + 1);
}

void UI::read_player_massage(string str)
{
    if (str == "Защита" || str == "защита")
    {
        std::cout << "Кидаем кубик..." << std::endl;
        int q = this->d3();
        Player->set_update_protection(q);
        std::cout << "Ваша защита увеличилась на " << q << std::endl;
    }
    if (str == "Атака" || str == "атака")
    {
        std::cout << "Кидаем кубик..." << std::endl;
        int a = this->d20();
        if (a >= monster->get_protection())
        {
            std::cout << "Вам выпало " << a << ". Защита монстра преодолена" << std::endl;
            if (a < 4)
            {
                std::cout << "Критический удар!" << std::endl;
                monster->set_damage(2 * Player->get_strength());
            }
            else
                monster->set_damage(Player->get_strength());
        }
        else
            std::cout << "Вам выпало " << a << ". Защита монстра не преодолена" << std::endl;
    }
}

void UI::monster_attack()
{
    int b = this->d20();
    if (b >= Player->get_protection())
    {
        Player->set_damage(monster->get_strength());
        std::cout << "Монстр нанес вам " << monster->get_strength() << " урона" << std::endl;
        Player->set_start_properties();
    }
    else
    {
        std::cout << "Монстр не смог пробить вашу защиту" << std::endl;
        Player->set_start_properties();
    }

}

void UI::update()
{
    if (!Player->ALIVE())
    {
        std::cout << "Ваш герой умер! Вы проиграли" << std::endl;
        std::cout << "У монстра осталось " << monster->get_hp() << " здоровья" << std::endl;
        finished = true;
    }
    if (!monster->ALIVE())
    {
        std::cout << "Вы победили монстра!" << std::endl;
        finished = true;
    }
}