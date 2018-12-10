#include "item.h"

Item::Item() { }

char Item::getState() {
	return state;
}

void Item::setState(char c) {
	state = c;
}

int Item:: getValue() { return 1; }
void Item::setValue(int n) {}

bool Item::getCanTake() {return true; };
void Item::setCanTake(bool b) {};
