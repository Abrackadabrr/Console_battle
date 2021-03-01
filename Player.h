#include "Game_Creature.h"

class Player: public Game_Creature
{
private:
    string battle_cry;
public:
    Player(string name);
};

