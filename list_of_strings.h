#include <iostream>
#include <string>
using namespace std;

class listt
{
private:
    struct uzzel
    {
        string name;
        string massage;
        uzzel* next;

        uzzel(string name,string massage)
        {
            this->name = name;
            this->massage = massage;
            next = NULL;
        }
    };
    uzzel* start;

    void clear_work(uzzel** sfl);

public:
    listt ();

    bool push_back(string name,string massage); //add element (string name,string massage) to the end of the list

    void print();

    unsigned int size() const;

    string find(string name) const;

    void clear(); //delete all elements (interface function, work function is private)

    ~listt();
};

