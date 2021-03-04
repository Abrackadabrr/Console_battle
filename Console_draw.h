#include<string>
#include <iostream>
#include "monster.h"
#include "Player.h"
#include "list_of_strings.h"
using namespace std;
class Console_draw {
private:
    Player* player;
    monster* monster;
    listt massages;
    string start[3];
    string info[3];
    string console_commands[3];
    ostream& os;
    istream& is;

    bool console_command();
    void read();
    void print(const string& name) const;

    string command;

public:

    Console_draw(ostream& os, istream& is);
    bool set_hello_hat() const;
    void read_random_symbol() const;
    void set_player_type() const;
    void set_goodbye() const;

    void set_duelers(Player* player1);

    string read_massage();

};