#include "Dice.h"
#include <iostream>
#include <time.h>

using namespace std;
int Dice::d3() {
	srand(time(NULL));
	return (rand() % 3 + 1);
}

int Dice::d6() {
	srand(time(NULL));
	return (rand() % 6 + 1);
}

int Dice::d10() {
	srand(time(NULL));
	return (rand() % 10 + 1);
}

int Dice::d20() {
	srand(time(NULL));
	return (rand() % 20 + 1);
}