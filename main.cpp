#include "monster.h"
#include "Player.h"
#include <iostream>

int main() {
    system("chcp 65001"); // отображает русские букафки
    Player Karim("Karim");
    monster LABA;
    while (Karim.ALIVE() and LABA.ALIVE()) {
        string event;
        cout << "Выбери, что делать, герой"<< endl << ">>>  "<<"  ";
        cin >> event;
        if (event == "hit") {
            LABA.set_damage(Karim.get_strength());
            cout << Karim.get_name()<<" нанёс урон " << LABA.get_name() << " в размере " << Karim.get_strength() << endl;
        }
        if (event == "protect") {
            Karim.set_update_protection(3);
            cout << "Твоя защита теперь " << Karim.get_protection() << endl;
        }
        Karim.set_damage(LABA.get_strength());
    }
    if (Karim.ALIVE()) cout << LABA.get_name()<<" lose";
}