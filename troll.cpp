//
// Created by Карим Вафин on 04.03.2021.
//

#include "troll.h"

troll::troll() {
    hp = 60;
    protection = 6;
    update_of_damage = 0;                       // на сколько увеличивается атака при атаке
    strength = 11;

    alive = true;
    name = "Лаба по терме";
}