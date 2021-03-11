//
// Created by Карим Вафин on 02.03.2021.
//
#include "Player.h"
#ifndef CONSOLE_BATTLE_WARRIOR_H
#define CONSOLE_BATTLE_WARRIOR_H


class warrior: public Player{
public:
    warrior(string name);
    DATA_BOX* attack(monster *monster) override;
};


#endif //CONSOLE_BATTLE_WARRIOR_H
