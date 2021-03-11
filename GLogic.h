#include "Player.h"
#include "monster.h"
#include <string>
#include "help_classes.h"
class GLogic {
private:
    monster* monster; // поинтер на монстра
    Player* Player; // поинтер на игрока
    bool finished; // поле означает, идет игровой цикл или заканчивается
    // через поинтеры GLogic будет "общаться" монстра и игрока, выставляя им различные праматры
public:
    GLogic(); // делает клassное присваивание как на сегодняшней лекции в референсы
    ~GLogic();
    DATA_BOX* read_player_massage(string str); // берет и чекает сообщение, которое отправил игрок
    DATA_BOX* monster_attack();
    DATA_BOX* update(); // проверяем, умер кто то или нет (закончилась игра или нет)
    int d3();
    int d20();
    class Player* create_player(string);
    class monster* create_monster();
    bool is_finished();
}; 
