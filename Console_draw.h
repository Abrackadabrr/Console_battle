#include<string>
#include <iostream>
#include "list_of_strings.h"
using namespace std;
class Console_draw {
private:
    listt massages;
    string start[5];
public:

    Console_draw();
    void print(string name);
    void set_hello_hat();
};