#include "UI.h"
#include "Dice.h"
#include <iostream>
#include "random.cpp"

UI::UI()
{
    monster = nullptr;
    Player = nullptr;
    finished = false;
}

void UI::read_player_massage(string str)
{
    if (str == "Защита" || str == "защита")
    {
        std::cout << "Кидаем кубик..." << std::endl;
        int q = d3();
        Player->set_update_protection(q);
        std::cout << "Ваша защита увеличилась на " << q << std::endl;
    }
    if (str == "Атака" || str == "атака")
    {
        std::cout << "Кидаем кубик..." << std::endl;
        int a = d20();
        if (a >= monster->get_protection())
        {
            monster->set_damage(Player->get_strength());
            std::cout << "Вам выпало " << a << ". Защита монстра преодолена" << std::endl;
        }
        else
            std::cout << "Вам выпало " << a << ". Защита монстра не преодолена" << std::endl;
    }
}

void UI::monster_attack()
{
    int a = d20();
    if (a >= monster->get_protection())
    {
        monster->set_damage(Player->get_strength());
        std::cout << "Монстр нанес вам " << a << " урона" << std::endl;
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