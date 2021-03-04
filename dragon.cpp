//
// Created by Карим Вафин on 03.03.2021.
//

#include "dragon.h"

dragon::dragon()
{
    hp = 70;
    protection = 5;
    update_of_damage = 0;                       // на сколько увеличивается атака при атаке
    strength = 10;

    alive = true;
    name = "dragon";
}