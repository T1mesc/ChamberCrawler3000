#ifndef _GRID_H_
#define _GRID_H_
#include "tile.h"
#include "item.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <vector>
#include "Dwarf.h"
#include "Halfling.h"
#include "Orc.h"
#include "Elf.h"
#include "Human.h"
#include "Merchant.h"
#include "Dragon.h"
#include "restoreHealth.h"
#include "poisonHealth.h"
#include "boostAtk.h"
#include "woundAtk.h"
#include "boostDef.h"
#include "woundDef.h"

class Grid {
	Character *PC;
	std::vector<Character *> enemies;
	Tile **map;
	std::string actions;
public:
	int level;
	Grid(Character *PC, int level);
	~Grid();

	void randomize(int *room, int *x, int *y);

	char getTileState(int x, int y);
	Character *getTileCTop(int x, int y);
	Item *getTileITop(int x, int y);
	Character *getPC();
	
	void charDrink(Character &c, int x, int y);
    void seePotions(Character &c);

	void setTileState(int x, int y, char state);
	void setTileCTop(int x, int y, Character *c);
	void setTileITop(int x, int y, Item *i);
	void setPC(Character *c);

	bool canMove(int x, int y);
	void charMove(Character &c, std::string s);

	void printMap();

	void charAttack(Character &c, int x, int y);
	bool checkAttack(Character &c, int x, int y);
	void NPCMove(bool freeze);

};

#endif
