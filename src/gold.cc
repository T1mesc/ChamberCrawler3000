#include "gold.h"

Gold::Gold(int n) {
	setState('G');
	value = n;
	if (n >= 6) {
	canTake = false;
	} else {
	canTake = true;
	}
}

int Gold::getValue() {
	return value;
}

void Gold::setValue(int n) {
value = n;
}

bool Gold::getCanTake() {
return canTake;
}

void Gold::setCanTake(bool b) {
canTake = b;
}
