//
// Created by iliyn on 04.03.2021.
//
#include <string>
#ifndef CONSOLE_BATTLE_HELP_CLASSES_H
#define CONSOLE_BATTLE_HELP_CLASSES_H

class DATA_BOX {
public:
    int dice_data;
    int int_data;
    int event_type;
    DATA_BOX(int dice, int damage, int type);
};

#endif //CONSOLE_BATTLE_HELP_CLASSES_H
