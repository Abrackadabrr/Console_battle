#include<string>
#include <iostream>
#include "list_of_strings.h"
using namespace std;
class Console_draw {
private:
    listt massages;
    string start[3];
    string players[3];
public:
    Console_draw();
    void print(string name);
    void set_hello_hat();
    void set_player_type();
};