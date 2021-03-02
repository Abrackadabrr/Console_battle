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
        auto pos = s.find(" ");
        if (pos != string::npos)
        {
            string s1 = s.substr(0,pos);
            string s2 = s.substr(pos+1);
            massages.push_back(s1, s2);
        }
    }
    in.close();
}

void Console_draw::print(string name)
{
    cout << this->massages.find(name)<<endl;
}