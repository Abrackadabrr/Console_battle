//
// Created by Карим Вафин on 02.03.2021.
//

#include "warrior.h"

warrior::warrior(string name)
{
    this->type = "warrior";
    this->hp = 70;
    this->protection = 10;
    this->update_of_protection = 3;
    this->strength = 10;
    this->alive = true;
    this->name = name;
}

DATA_BOX* warrior::attack(Monster* monster1) {
    DATA_BOX* data = nullptr;

    int a = this->d20();
    if (a >= monster1->get_protection()) {
        if (this->d20() < 4) {
            monster1->set_damage(2 * this->get_strength());
            data = new DATA_BOX(a, 2 * this->get_strength(), 10100);
        } else {
            monster1->set_damage(this->get_strength());
            data = new DATA_BOX(a, this->get_strength(), 10001);
        }
    }
    else
        data = new DATA_BOX(a,0,10000);
    return data;
}