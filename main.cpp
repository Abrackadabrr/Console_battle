#include "monster.h"
#include "Player.h"
#include <iostream>

int main()
{
    Player Karim ("Karim");
    std::cout << Karim.get_hp() << std::endl;
    std::cout << Karim.get_strength() << std::endl;
    std::cout << Karim.get_protection() << std::endl;
    Karim.set_update_protection(10);
    std::cout << Karim.get_protection() << std::endl;
    Karim.set_damage(1000);
    if (!Karim.check_alive())
    {
        std::cout << "YOU DIED" << std::endl;
    }
    std::cout << Karim.get_hp() << std::endl;

    monster LABA;
    std::cout << LABA.get_hp() << std::endl;
    std::cout << LABA.get_strength() << std::endl;
    std::cout << LABA.get_protection() << std::endl;
    LABA.set_update_protection(10);
    std::cout << LABA.get_protection() << std::endl;
    LABA.set_damage(1000);
    if (!LABA.check_alive())
    {
        std::cout << "YOU DIED" << std::endl;
    }
    std::cout << LABA.get_hp() << std::endl;
}
