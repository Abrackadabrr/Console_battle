#ifndef CONSOLE_BATTLE_MONSTER_H
#define CONSOLE_BATTLE_MONSTER_H
#include "help_classes.h"
#include <string>
#include "Player.h"

using namespace  std;
class Monster {
protected:
    int hp;
    int protection;
    int update_of_damage;                       // на сколько увеличивается атака при атаке
    int strength;

    bool alive;
    string name;
    void set_start_properties();                               // восстанавливаем динамические параметры

public:
    string type;

    Monster() {}
    int get_hp () const;
    int get_protection () const;
    int get_strength () const;
    string get_name() const;
    bool ALIVE();                                           // жывой или  подох

    void set_damage(int damage);                            // получаем урон в размере damage
    void set_update_strength(int upd);                      // увеличивает атаку на upd

    virtual DATA_BOX* attack_(Player* player) = 0;
};

#endif //CONSOLE_BATTLE_MONSTER_H