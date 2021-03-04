#ifndef CONSOLE_BATTLE_PLAYER_H
#define CONSOLE_BATTLE_PLAYER_H

#include <string>
using namespace  std;
class Player {
protected:
    int hp;
    int protection;
    int update_of_protection;                       // на сколько увеличивается защита при защите
    int strength;

    bool alive;
    string name;

public:

    int get_hp () const;
    int get_protection () const;
    int get_strength () const;
    string get_name() const;
    bool ALIVE();
    void set_start_properties();
    void set_damage(int damage);                                // получаем урон в размере damage
    void set_update_protection(int upd);                        // увеличивает защиту на update_of_protection
};

#endif //CONSOLE_BATTLE_PLAYER_H