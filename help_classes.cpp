//
// Created by iliyn on 04.03.2021.
//

#include "help_classes.h"

DATA_BOX::DATA_BOX(int dice, int damage, int type)
{
    this->event_type = type;
    this->int_data = damage;
    this->dice_data = dice;
}


