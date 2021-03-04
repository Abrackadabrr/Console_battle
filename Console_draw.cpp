#include "Console_draw.h"
#include <string>
#include <fstream>
using namespace std;

Console_draw::Console_draw(ostream& os, istream& is): os(os), is(is)
{
    string s;
    ifstream in("F:\\MIPT\\1st level\\Chapter 2\\IT\\C++\\Console_battle\\console.txt");

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
    this->os << this->massages.find(name);
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

void Console_draw::set_cpravka() const{
    this->print("справка по командам");
}

void Console_draw::set_duel() const
{
    this->print("дуэль");
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

bool Console_draw::read_random_symbol() const
{
    char c;
    (this->is).get(c);
    if (c == '\n') return false;
    else return true;
}

string Console_draw::read_massage()
{
    while(console_command()) {}
    return this->command;
}

string Console_draw::read_massage_about_player()
{
    string s = this->read_massage();
    while (s != "1" && s != "2")
    {
        this->print("некор кмнд");
        s = this->read_massage();
    }
    return s;
}

void Console_draw::set_player(Player* player1)
{
    this->player = player1;
}

void Console_draw::set_monster(class monster* monster1)
{
    this->monster = monster1;
}

bool Console_draw::drawback(DATA_BOX* data)
{
    if (!data) {this->print("некор кмнд"); return false;};
    switch (data->event_type)
    {
        case (12): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("ув защиты и");
            this->os << data->int_data << endl;
            delete data;
            break;
        }
        case (11): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("пробитие м");
            this->print("урон м");
            this->os <<" "<< data->int_data << endl;
            delete data;
            break;
        }
        case (13): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("критическое м");
            this->os << data->int_data << endl;
            delete data;
            break;
        }
        case (10): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("непробитие м");
            delete data;
            break;
        }
        case (21):{
            this->os << "Ход "; this->os << monster->get_name() <<endl;
            this->print("пробитие и");
            this->os <<"Бросок "<< data->dice_data << " против защиты героя "<<player->get_protection()<<endl;
            this->print("урон и");
            this->os <<" "<< data->int_data<<endl;
            delete data;
            break;
        }
        case (20):{
            this->os << "Ход "; this->os << monster->get_name() <<endl;
            this->print("непробитие и");
            this->os <<"Бросок "<< data->dice_data << " против защиты героя "<<player->get_protection()<<endl;
            delete data;
            break;
        }
        case (30): {
            this->print("пор");
            this->os << monster->get_hp() << endl;
            delete data;
            break;
        }
        case (31): {
            this->print("поб");
            this->os << monster->get_hp() << endl;
            delete data;
            break;
        }
        case (32): {
            this->print("нич");
            this->os << monster->get_hp() << endl;
            delete data;
            break;
        }
    }
    return true;
}