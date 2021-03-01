#include "monster.h"
#include <iostream>
monster::monster()
{
    this->name = LABA;
    std::cout << "Monster ", this->get_name(), "is created" << std::endl;
    hp = 1000;
    protection = 100;
    update_of_protection = 30;
    strength = 100;
}