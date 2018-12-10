#include "Dragon.h"

Dragon::Dragon(int x, int y): NPC("Dragon"){
	gx = x;
	gy = y;
}

int Dragon::goldX(){
	return gx;
}

int Dragon::goldY(){
	return gy;
}

