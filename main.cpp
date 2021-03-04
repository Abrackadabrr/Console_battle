#include "monster.h"
#include "Player.h"
#include <iostream>
#include "Console_draw.h"
#include <ctime>
#include "UI.h"

int main()
{
    srand(time(NULL));

    Console_draw console(cout, cin);
    UI user;
    console.set_hello_hat();
    while(console.read_random_symbol());
    console.set_player_type();
    console.set_player(user.create_player(console.read_massage_about_player()));
    console.set_monster(user.create_monster());
    console.set_cpravka();
    console.set_duel();
    while(!user.is_finished())
    {
        if (console.drawback(user.read_player_massage(console.read_massage()))) {
            console.drawback(user.monster_attack());
            user.update();
        }
    }
    console.set_goodbye();
    return 0;
}
