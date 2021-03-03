//
// Created by Карим Вафин on 02.03.2021.
//

#include "warrior.h"

warrior::warrior(string name)
{
    this->hp = 100;
    this->protection = 10;
    this->update_of_protection = 3;
    this->strength = 10;
    this->alive = true;
    this->name = name;
}