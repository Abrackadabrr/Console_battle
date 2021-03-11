#include "INOUT.h"
#include <string>
#include <fstream>
using namespace std;

INOUT::INOUT(ostream& os, istream& is): os(os), is(is)
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
}

void INOUT::load_player_commands(string type)
{
    string s;
    ifstream in;
    if (type == "warrior")
        in = ifstream ("F:\\MIPT\\1st level\\Chapter 2\\IT\\C++\\Console_battle\\warrior.txt");

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
}

void INOUT::load_monster_commands(string type)
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
}

void INOUT::print(const string& name) const
{
    this->os << this->massages.find(name);
}

bool INOUT::set_hello_hat() const
{
    this->os  << endl;
    for(int i = 0; i < 3; i++){
        this->print(start[i]);
    }
    return true;
}

void INOUT::set_player_type() const
{
    this->print("выбор игрока");
}

void INOUT::set_cpravka() const
{
    this->os << "Справка по комнадам и способностям для вашего героя" <<endl;
    this->os << endl;
    this->print("ЗАЩИТА");
    this->print("АТАКА");
    this->print("ИНФО");
    this->print("СПРАВКА К");
    for (int i = 0; i < player->get_amount_of_actions(); i ++)
    {
        if(player->type == "warrior") this->print("КРИТ УДАР");
    }
}

void INOUT::set_duel() const
{
    this->print("дуэль");
}

void INOUT::set_goodbye() const
{
    this->print("выход");
}

bool INOUT::console_command()
{
    bool is_console_command = false;
    this->read();
    for (int i = 0; i < 2; i ++) if (this->command == this->console_commands[i])
    {
        is_console_command = true;
    }
    if (is_console_command)
    {
        if (this->command == "инфо")
        {
            this->os << "Здоровье героя " << player->get_hp() << endl;
            this->os << "Защита героя " << player->get_protection() << endl;
            this->os << "Атака героя " << player->get_strength() << endl;
            this->os << endl;
            this->os << "Здоровье монстра " << monster->get_hp() << endl;
            this->os << "Защита монстра " << monster->get_protection() << endl;
            this->os << "Атака монстра " << monster->get_strength() << endl;
        }
        if (this->command == "справка по командам")
        {
            this->set_cpravka();
        }
    }
    return is_console_command;
}

void INOUT::read()
{
    this->os << this->massages.find("ввод");
    getline(this->is, this->command);
}

bool INOUT::read_random_symbol() const
{
    char c;
    (this->is).get(c);
    if (c == '\n') return false;
    else return true;
}

string INOUT::read_massage()
{
    while(console_command()) {}
    return this->command;
}

string INOUT::read_massage_about_player()
{
    string s = this->read_massage();
    while (s != "1" && s != "2")
    {
        this->print("некор кмнд");
        s = this->read_massage();
    }
    return s;
}

void INOUT::set_player(Player* player1)
{
    if (player1) this->os << "ВАРНИНГ БЛЯТЬ";
    this->player = player1;
    this->load_player_commands(player1->type);
}

void INOUT::set_monster(class monster* monster1)
{
    this->monster = monster1;
    this->print("спавн монстр"); this->os << " " << monster->get_name()<<endl;
}

bool INOUT::drawback(DATA_BOX* data)
{
    if (!data) {this->print("некор кмнд"); return false;};
    switch (data->event_type)
    {
        case (10002): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("ув защиты и");
            this->os << data->int_data << endl;
            break;
        }
        case (10001): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("пробитие м");
            this->print("урон м");
            this->os <<" "<< data->int_data << endl;
            break;
        }
        case (10100): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("критическое м");
            this->os << data->int_data << endl;
            break;
        }
        case (10000): {
            this->print("ход и");
            this->print("кубик");
            this->os << data->dice_data <<endl;
            this->print("непробитие м");
            break;
        }
        case (20001):{
            this->os << "Ход "; this->os << monster->get_name() <<endl;
            this->print("пробитие и");
            this->os <<"Бросок "<< data->dice_data << " против защиты героя "<<player->get_protection()<<endl;
            this->print("урон и");
            this->os <<" "<< data->int_data<<endl;
            break;
        }
        case (20000):{
            this->os << "Ход "; this->os << monster->get_name() <<endl;
            this->print("непробитие и");
            this->os <<"Бросок "<< data->dice_data << " против защиты героя "<<player->get_protection()<<endl;
            break;
        }
    }
    if (data) delete data;
    return true;
}

void INOUT::is_end(DATA_BOX* data)
{
    if (!data) return;
    switch (data->event_type)
    {
        case (30): {
            this->print("пор");
            this->os << monster->get_hp() << endl;
            delete data;
            break;
        }
        case (31): {
            this->print("поб");
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
}