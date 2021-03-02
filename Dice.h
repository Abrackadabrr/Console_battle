#pragma once

class Dice {
protected:
    int sides;
public:
    int roll();
};

class D3: public Dice{
public:
    D3();
};

class D6: public Dice {
public:
    D6();
};

class D10: public Dice {
public:
    D10();
};

class D20: public Dice {
public:
    D20();
};
