#include "Player.h"
#include "monster.h"
#include <string>
class UI {
private:
    monster& monster; // констовый референс на монстра
    Player& Player; // констовый референс на игрока
    // через референсы UI будет "общаться" монстра и игрока, выставляя им различные праматры
public:
    UI(); // делает клassное присваивание как на сегоднящней лекции в референсы
    string read_player_massage(); // считывает сообщение игрока (можно в принципе и перегрузить опрератов ввода с экрана)
    void check_player_massage(string massage); // берет и чекает сообщение, которое отправил игрок

}; 

//