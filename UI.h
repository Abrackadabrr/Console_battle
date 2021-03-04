#include "Player.h"
#include "monster.h"
#include <string>

class UI {
private:
    monster* monster; // поинтер на монстра
    Player* Player; // поинтер на игрока
    bool finished; // поле означает, идет игровой цикл или заканчивается
    // через поинтеры UI будет "общаться" монстра и игрока, выставляя им различные праматры
public:
    UI(); // делает клassное присваивание как на сегодняшней лекции в референсы
    ~UI();
    void read_player_massage(string str); // берет и чекает сообщение, которое отправил игрок
    void monster_attack();
    void update(); // проверяем, умер кто то или нет (закончилась игра или нет)
    int d3();
    int d20();
    class Player* create_player(string);
    class monster* create_monster();
    bool is_finished();
}; 

//