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
    console.read_random_symbol();
    console.set_player_type();
    console.set_player(user.create_player(console.read_massage()));
    console.set_monster(user.create_monster());
    while(!user.is_finished())
    {
        user.read_player_massage(console.read_massage());
        user.monster_attack();
        user.update();
    }
    return 0;
}
