//
// Created by Карим Вафин on 03.03.2021.
//

#ifndef CONSOLE_BATTLE_DRAGON_H
#define CONSOLE_BATTLE_DRAGON_H
#include "Monster.h"

class dragon: public Monster
{
public:
    dragon();
    DATA_BOX* attack_(Player* player) override;
};


#endif //CONSOLE_BATTLE_DRAGON_H
