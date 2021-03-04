#include "Console_draw.h"
#include <string>
#include <fstream>
using namespace std;

Console_draw::Console_draw(ostream& os, istream& is): os(os), is(is)
{
    string s;
    ifstream in("/Users/karimvafin/Documents/Repositories/MIPT/Console_battle/console.txt");

    while (getline(in, s))
    {
        auto pos = s.find("|");
        if (pos != string::npos)
        {
            string s1 = s.substr(0,pos);
            string s2 = s.substr(pos+1);
            for (int i = 0; i < s2.length(); i++)
            {
                if (s2[i] == 'p') s2[i] = '\n';
            }
            massages.push_back(s1, s2);
        }
    }
    in.close();

    this->start[0] = "приветствие";
    this->start[1] = "правила";
    this->start[2] = "начать";

    this->console_commands[0] = "справка по командам";
    this->console_commands[1] = "инфо";
    this->console_commands[2] = "справка по героям";
}

void Console_draw::print(const string& name) const
{
    this->os << this->massages.find(name)<<endl;
}

bool Console_draw::set_hello_hat() const
{
    this->os  << endl;
    for(int i = 0; i < 3; i++){
        this->print(start[i]);
    }
    return true;
}

void Console_draw::set_player_type() const
{
    this->print("выбор игрока");
}

void Console_draw::set_goodbye() const
{
    this->print("выход");
}

bool Console_draw::console_command()
{
    this->read();
    for (int i = 0; i < 3; i ++) if (this->command == this->console_commands[i]) {
        this->print(this->console_commands[i]);
        return true;
        }
    return false;
}

void Console_draw::read()
{
    this->os << this->massages.find("ввод");
    getline(this->is, this->command);
}

void Console_draw::read_random_symbol() const
{
    (this->is).get();
}

string Console_draw::read_massage()
{
    while(console_command()) {}
    return this->command;
}

void Console_draw::set_player(Player* player1)
{
    this->player = player1;
}

void Console_draw::set_monster(class monster* monster1)
{
    this->monster = monster1;
}