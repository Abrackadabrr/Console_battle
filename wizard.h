//
// Created by iliyn on 05.03.2021.
//

#ifndef CONSOLE_BATTLE_WIZARD_H
#define CONSOLE_BATTLE_WIZARD_H

#include "Player.h"

class wizard: public Player {
public:
    wizard(string name);
    DATA_BOX* attack(monster* monster1) override;
};


#endif //CONSOLE_BATTLE_WIZARD_H
