#include "troll.h"

troll::troll() {
    hp = 60;
    protection = 6;
    update_of_damage = 0;                       // на сколько увеличивается атака при атаке
    strength = 11;

    alive = true;
    name = "troll";
    this->type = "troll";
}

DATA_BOX* troll::attack_(Player* player){
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