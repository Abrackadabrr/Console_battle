#include <string>
class Player {
protected:
    int hp;
    int protection;
    int update_of_protection;                       // на сколько увеличивается защита при защите
    int strength;

    bool alive;

    void set_start_properties();

public:
    Player();
    int get_hp () const;
    int get_protection () const;
    int get_strength () const;
    bool check_alive ();

    void set_damage(int damage);                            // наносим урок в размере силы
    void update_protection(int upd);                        // увеличивает защиту на update_of_protection

};
