#ifndef _TILE_H_
#define _TILE_H_
#include "Character.h"
#include "item.h"
#include "gold.h"

class Tile {
	char state;
	Character *charTop;
	Item *itemTop;
public:
	Tile();
	~Tile();
	bool isEmpty();

	char getState(); // getters
	Character *getCharTop();
	Item *getItemTop();

	void setState(char s); // setters
	void setCharTop(Character *c);
	void setItemTop(Item *i);

	void print();
	bool canMove();
	bool ifDead(std::string&out, Character &c);

};

#endif
