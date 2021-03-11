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
    this->type = "dragon";
}

DATA_BOX* dragon::attack_(Player* player) {
    int b = player->d20();
    DATA_BOX* data;
    if (b >= player->get_protection())
    {
        player->set_damage(this->get_strength());
        data = new DATA_BOX(b, this->get_strength(), 20001);
    }
    else
    {
        data = new DATA_BOX(b, 0, 20000);
    }
    return data;
}