//
// Created by Карим Вафин on 04.03.2021.
//
#include "Monster.h"
#ifndef CONSOLE_BATTLE_TROLL_H
#define CONSOLE_BATTLE_TROLL_H


class troll: public Monster {
public:
    troll();
    DATA_BOX* attack_(Player* player) override;
};


#endif //CONSOLE_BATTLE_TROLL_H
