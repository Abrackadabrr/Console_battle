#include "Dice.h"
#include <iostream>
#include <time.h>
using namespace std;

int Dice::roll() {
    srand(time(NULL));
    return (rand() % this->sides + 1);
}

D3::D3() {
    this->sides = 3;
}

D6::D6() {
    this->sides = 6;
}

D10::D10() {
    this->sides = 10;
}

D20::D20() {
    this->sides = 20;
}