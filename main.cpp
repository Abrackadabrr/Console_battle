#include "monster.h"
#include "Player.h"
#include <iostream>
#include "INOUT.h"
#include <ctime>
#include "GLogic.h"

int main()
{
    srand(time(NULL));

    INOUT console(cout, cin);
    GLogic logic;
    console.set_hello_hat();
    while(console.read_random_symbol());
    console.set_player_type();
    console.set_player(logic.create_player(console.read_massage_about_player()));
    console.set_monster(logic.create_monster());
    console.set_cpravka();
    console.set_duel();
    while(!logic.is_finished())
    {
        if (console.drawback(logic.read_player_massage(console.read_massage()))) {
            console.drawback(logic.monster_attack());
            console.is_end(logic.update());
        }
    }
    console.set_goodbye();
    return 0;
}
