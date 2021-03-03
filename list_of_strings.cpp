#include "list_of_strings.h"

listt::listt ()
{
    start = NULL;
}

bool listt:: push_back(string name,string massage)
{
    uzzel** sfl = &(this -> start);
    uzzel* tmp = new uzzel(name, massage);
    while (*sfl != NULL)
    {
        sfl = &((*sfl)->next);
    }
    *sfl = tmp;
    return true;
}

void listt::print()
{
    uzzel* tmp = start;
    if (!tmp) cout << "empty list";
    while (tmp != NULL)
    {
        cout << tmp->name << " # "<< tmp->massage<<endl;
        tmp = (tmp)->next;
    }
    cout << endl<<endl;
    return;
}

unsigned int listt::size()
{
    uzzel* sfl = this -> start;
    unsigned int size = 0;
    while (sfl != NULL)
    {
        sfl = (sfl)->next;
        size++;
    }
    return size;
}

void listt::clear_work(uzzel** sfl)
{
    if (*sfl == NULL) return;
    clear_work(&((*sfl)->next));
    delete *sfl;
    *sfl = NULL;
    return;
}

void listt::clear()
{
    uzzel** sfl = &(this -> start);
    this ->clear_work(sfl);
}

listt::~listt()
{
    this -> clear();
}

string listt::find(string name)
{
    uzzel* sfl = this -> start;
    int counter_iter = 1;
    unsigned size = this->size();
    while (!(sfl->name == name) and counter_iter <= size)
    {
        sfl = (sfl)->next;
        counter_iter ++;
    }
    if (!sfl) return "nope";
    return sfl->massage;
}
