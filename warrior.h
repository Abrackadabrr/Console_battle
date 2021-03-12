#include "Player.h"
#ifndef CONSOLE_BATTLE_WARRIOR_H
#define CONSOLE_BATTLE_WARRIOR_H


class warrior: public Player{
public:
    warrior(string name);
    DATA_BOX* attack(Monster* monster1) override;
};


#endif //CONSOLE_BATTLE_WARRIOR_H
