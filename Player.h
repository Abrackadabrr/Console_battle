#ifndef CONSOLE_BATTLE_PLAYER_H
#define CONSOLE_BATTLE_PLAYER_H
#include "Monster.h"
#include "help_classes.h"
#include <string>

using namespace  std;
class Player {
protected:
    int amount_of_actions;

    int hp;
    int protection;
    int update_of_protection;                       // на сколько увеличивается защита при защите
    int strength;

    bool alive;
    string name;

public:
    string type;

    Player();
    int get_hp () const;
    int get_protection () const;
    int get_strength () const;
    int get_amount_of_actions() const;
    string get_name() const;
    bool ALIVE();
    void set_start_properties();
    void set_damage(int damage);                                // получаем урон в размере damage

    int d3();
    int d20();

    virtual DATA_BOX* attack(Monster* monster1) = 0;
    DATA_BOX* set_update_protection();
};

#endif //CONSOLE_BATTLE_PLAYER_H