#include <string>
#include <iostream>
#include "Monster.h"
#include "Player.h"
#include "list_of_strings.h"
#include "help_classes.h"
using namespace std;
class INOUT {
private:
    Player* player;
    Monster* monster;
    listt massages;
    string start[3];
    string info[3];
    string console_commands[2];
    ostream& os;
    istream& is;

    bool console_command();
    void read();
    void print(const string& name) const;
    void load_monster_commands(string s);
    void load_player_commands(string s);
    string command;

public:

    INOUT(ostream& os, istream& is);
    bool set_hello_hat() const;
    bool read_random_symbol() const;
    void set_player_type() const;
    void set_goodbye() const;
    void set_cpravka() const;
    void set_duel() const;

    void set_player(Player* player1);
    void set_monster(Monster* monster1);

    string read_massage();
    string read_massage_about_player();

    bool drawback(DATA_BOX* data);
    void is_end(DATA_BOX* data);
};