#include <string>
using namespace  std;
class Game_Creature {
protected:
    int hp;
    int protection;
    int update_of_protection;                       // на сколько увеличивается защита при защите
    int strength;

    bool alive;
    string name;
    void set_start_properties();

public:
    Game_Creature();
    int get_hp () const;
    int get_protection () const;
    int get_strength () const;
    string get_name() const;
    bool check_alive ();

    void set_damage(int damage);                            // наносим урок в размере силы
    void set_update_protection(int upd);                        // увеличивает защиту на update_of_protection
};
