#include "Console_draw.h"
#include<string>
#include <fstream>
using namespace std;
Console_draw::Console_draw()
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
                if (s2[i] == 'n') s2[i] = '\n';
            }
            massages.push_back(s1, s2);
        }
    }
    in.close();

    start[0] = "приветствие";
    start[1] = "правила";
    start[2] = "начать";

    players[0] = "выбор игрока";
    players[1] = "воин";
    players[2] = "волшебник";

}

void Console_draw::print(string name)
{
    cout << this->massages.find(name)<<endl;
}

void Console_draw::set_hello_hat()
{
    for(int i = 0; i < 3; i++){
        cout << this->massages.find(start[i])<<endl;
    }
}

void Console_draw::set_player_type()
{
    for(int i = 0; i < 3; i++){
        cout << this->massages.find(players[i])<<endl;
    }
}
