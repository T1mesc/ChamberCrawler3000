#include "grid.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <vector>

Grid::Grid(Character *PC, int level) : level(level) {
	this->PC = PC;
	map = new Tile *[25];
	for(int i = 0; i < 25; ++i) {
		map[i] = new Tile[79];
	}

	std::string floor[25];
	floor[0] =  "|-----------------------------------------------------------------------------|";
    floor[1] =  "|                                                                             |";
    floor[2] =  "| |--------------------------|        |-----------------------|               |";
    floor[3] =  "| |..........................|        |.......................|               |";
    floor[4] =  "| |..........................+########+.......................|-------|       |";
    floor[5] =  "| |..........................|   #    |...............................|--|    |";
    floor[6] =  "| |..........................|   #    |..................................|--| |";
    floor[7] =  "| |----------+---------------|   #    |----+----------------|...............| |";
    floor[8] =  "|            #                 #############                |...............| |";
    floor[9] =  "|            #                 #     |-----+------|         |...............| |";
    floor[10] = "|            #                 #     |............|         |...............| |";
    floor[11] = "|            ###################     |............|   ######+...............| |";
    floor[12] = "|            #                 #     |............|   #     |...............| |";
    floor[13] = "|            #                 #     |-----+------|   #     |--------+------| |";
    floor[14] = "|  |---------+-----------|     #           #          #              #        |";
    floor[15] = "|  |.....................|     #           #          #         |----+------| |";
    floor[16] = "|  |.....................|     ########################         |...........| |";
    floor[17] = "|  |.....................|     #           #                    |...........| |";
    floor[18] = "|  |.....................|     #    |------+--------------------|...........| |";
    floor[19] = "|  |.....................|     #    |.......................................| |";
    floor[20] = "|  |.....................+##########+.......................................| |";
    floor[21] = "|  |.....................|          |.......................................| |";
    floor[22] = "|  |---------------------|          |---------------------------------------| |";
    floor[23] = "|                                                                             |";
    floor[24] = "|-----------------------------------------------------------------------------|";
    for(int i = 0; i < 25; ++i) {
    	for(int h = 0; h < 79; ++h) {
    		map[i][h].setState(floor[i][h]);
    		map[i][h].setCharTop(nullptr);
    		map[i][h].setCharTop(nullptr);
    	}

    }

    int room;
    int x;
    int y;

    randomize(&room, &x, &y);
    PC->setX(x);
    PC->setY(y);
    map[y][x].setCharTop(PC);

    while(1) {
    	int stairRoom = room;
    	randomize(&room, &x, &y);
    	if (room != stairRoom) {
    		setTileState(x, y, '\\');
    		break;
    	}

    }

    for(int i = 0; i < 20; ++i) {
    	
    	int random = rand() % 18;
    	if (random < 3) {
    		Dwarf d;                 
    		enemies.push_back(new Dwarf);
    		*(enemies[i]) = d;
    	} else if (random < 8) {
    		Halfling l;
    		enemies.push_back(new Halfling);
    		*(enemies[i]) = l; 
    	} else if (random < 12) {
    		Human h;
    		enemies.push_back(new Human);
    		*(enemies[i]) = h;
    	} else if (random < 14) {
    		Elf e;
    		enemies.push_back(new Elf);
    		*(enemies[i]) = e;
    	} else if (random < 16) {
    		Orc o;
    		enemies.push_back(new Orc);
    		*(enemies[i]) = o;
    	} else if (random < 18) {
    		Merchant m;
    		enemies.push_back(new Merchant);
    		*(enemies[i]) = m;
    	}
    	randomize(&room, &x, &y);
    	enemies[i]->setX(x);
    	enemies[i]->setY(y);
    	setTileCTop(x, y, enemies[i]);
    }

  for (int i = 0; i < 10; ++i) {
        int random = rand() % 8;
        randomize(&room, &x, &y);
        if (random < 4) {
            Item *i = new Gold(2);
            setTileITop(x, y, i);
        } else if (random < 6) {
            Item *i = new Gold(1);
            setTileITop(x, y, i);
        } else {
        	while(1) {
        		bool b = false;
                for(int i = x - 1; i <= x + 1; ++i) {                   
                	for(int h = y - 1; h <= y + 1; ++h) {
                        if (!b && (map[h][i]).isEmpty() && ((i != x) || (h != y))) {
                        	Item *I = new Gold(6);
                        	setTileITop(x, y, I);
                        	Dragon d(x, y);
                        	enemies.push_back(new Dragon(x, y));
                        	*(enemies[enemies.size() - 1]) = d;
                        	enemies[enemies.size() - 1]->setX(i);
                        	enemies[enemies.size() - 1]->setY(h);
                        	setTileCTop(i, h, enemies[enemies.size() - 1]);
                        	b = true;
                        }
                    }
                }
                if (b) break;
                randomize(&room, &x, &y);
            }
        }
        random = rand() % 6;
         randomize(&room, &x, &y);
        if (random == 0) {
            Item *i = new restoreHealth();
            setTileITop(x, y, i);
        }
        if (random == 1) {
            Item *i = new poisonHealth();
            setTileITop(x, y, i);
        }
        if (random == 2) {
            Item *i = new boostAtk();
            setTileITop(x, y, i);
        }
        if (random == 3) {
            Item *i = new woundAtk();
            setTileITop(x, y, i);
        }
        if (random == 4) {
            Item *i = new boostDef();
            setTileITop(x, y, i);
        }
        if (random == 5) {
            Item *i = new woundDef();
            setTileITop(x, y, i);
        }


    }

}

void Grid::seePotions(Character &c) {
    for (int i = c.getX() - 1; i <= c.getX() + 1; ++i) {
        for (int h = c.getY() - 1; h <= c.getY() + 1; ++h) {
            if (getTileITop(i, h)) {
            	if ((getTileITop(i, h))->getState() == 'P') {
            		Potion *p = dynamic_cast<Potion *>(getTileITop(i, h));
            		actions += "Player sees ";
            		p->print(actions);
            }
            }

        }
    }
}

void Grid::charDrink(Character &c, int x, int y) {
    if(getTileITop(x, y)){
    	if (getTileITop(x, y)->getState() == 'P') {
    	Potion *p = dynamic_cast<Potion *>(getTileITop(x, y));
        p->Affect(actions, c);
        delete getTileITop(x, y);
        setTileITop(x, y, nullptr);
    }
    }
    else {
        actions += "Nothing to be used. ";
    }
}



void Grid::randomize(int *room, int *x, int *y) {
	int x_min;
    int x_max;
    int y_min;
    int y_max;

    int random = rand();
    if(random % 5 == 0) {
    	x_min = 3;
    	x_max = 28;
    	y_min = 3;
    	y_max = 6;
    } else if (random % 5 == 1) {
    	x_min = 39;
    	x_max = 75;
    	y_min = 3;
    	y_max = 12;
    } else if (random % 5 == 2) {
    	x_min = 38;
    	x_max = 49;
    	y_min = 10;
    	y_max = 12;
    } else if (random % 5 == 3) {
    	x_min = 4;
    	x_max = 20;
    	y_min = 15;
    	y_max = 21;
    } else if (random % 5 == 4) {
    	x_min = 33;
    	x_max = 75;
    	y_min = 16;
    	y_max = 21;
    }

    while(1) {
    	int x2 = rand();
    	x2 = (x2 % (x_max - x_min)) + x_min;
    	int y2 = rand();
    	y2 = (y2 % (y_max - y_min)) + y_min;
    	if((getTileState(x2, y2) == '.') && (getTileCTop(x2, y2) == nullptr) 
&& ((random % 5 != 1) || ((x2 > 58) || (y2 < 7)))) {
    		*room = random % 5;
    		*x = x2;
    		*y = y2;
    		return;
    	}

    }
}

Grid::~Grid() {
	for(int i = 0; i < 25; ++i) {
		delete [] map[i];
	}
	delete [] map;
    for(int i = 0; i < enemies.size(); ++i) {
        delete enemies[i];
    }
}

char Grid::getTileState(int x, int y) {
	return map[y][x].getState();
}

Character *Grid::getTileCTop(int x, int y) {
	return map[y][x].getCharTop();
}

Item *Grid::getTileITop(int x, int y) {
	return map[y][x].getItemTop();
}

Character *Grid::getPC() {
	return PC;
}

void Grid::setTileState(int x, int y, char state) {
	map[y][x].setState(state);
}

void Grid::setTileCTop(int x, int y, Character *c) {
	map[y][x].setCharTop(c);
}

void Grid::setTileITop(int x, int y, Item *i) {
	map[y][x].setItemTop(i);
}

void Grid::setPC(Character *c) {
	PC = c;
}

bool Grid::canMove(int x, int y) {
	return map[y][x].canMove();
}

bool Grid::checkAttack(Character &c, int x, int y) {
    for (int i = x - 1; i <= x + 1; ++i) {
        for (int h = y - 1; h <= y + 1; ++h) {
            if ((c.getX() != i) || (c.getY() != h)) {
            	if ((getTileCTop(i, h)) && (getTileCTop(i, h)->getRace() == PC->getRace())) {
                charAttack(c, i, h);
                return true;
            }
            }

        }
    }
    return false;
}

void Grid::charAttack(Character &c, int x, int y) {
    if(getTileCTop(x, y)) {
        c.Attack(actions, *getTileCTop(x,y));
        bool isDead = map[y][x].ifDead(actions, c);
        if (isDead) {
         if(getTileCTop(x,y)->getRace() != PC->getRace()) {
            for(int i = 0; i < enemies.size(); ++i) {
                if((enemies[i]->getX() == x) &&
                   (enemies[i]->getY() == y)) {
                	if (getTileCTop(x,y)->getRace() == "Dragon") {
                		Character *cp = getTileCTop(x,y);
                        getTileITop(cp->goldX(),cp->goldY())->setCanTake(true);
                    }
                    enemies.erase(enemies.begin() + i);
                    setTileCTop(x,y, nullptr);
                }
                }
            }       
        }
    } else {
    	if (c.getRace() == PC->getRace()) {
        actions += "Nothing to be attacked. ";
    }
    }

}



void Grid::charMove(Character &c, std::string s) {
    bool isPC = false;
    if(c.getRace() == PC->getRace()) {
        isPC = true;
    }
	int x = c.getX();
	int y = c.getY();
	if (s == "no") {
		if (canMove(x, y - 1) && (isPC || (getTileState(x, y - 1) == '.'))) {
			setTileCTop(x, y - 1, &c);
			setTileCTop(x, y, nullptr);
			c.setY(y - 1);
            if(isPC) {
                actions += "PC moves north. ";
				seePotions(c);
            }
		}	else {
            if(isPC) {
                actions += "Cannot move there. ";
            }

        }
	} else if (s == "ne") {
		if (canMove(x + 1, y - 1) && (isPC || (getTileState(x + 1, y - 1) == '.'))) {
			setTileCTop(x + 1, y - 1, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x + 1);
			c.setY(y - 1);
            if(isPC) {
                actions += "PC moves northeast. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	}else if (s == "ea") {
		if (canMove(x + 1, y) && (isPC || (getTileState(x + 1, y) == '.'))) {
			setTileCTop(x + 1, y, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x + 1);
            if(isPC) {
                actions += "PC moves east. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	} else if (s == "se") {
		if (canMove(x + 1, y + 1) && (isPC || (getTileState(x + 1, y + 1) == '.'))) {
			setTileCTop(x + 1, y + 1, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x + 1);
			c.setY(y + 1);
            if(isPC) {
                actions +="PC moves southeast. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	}else if (s == "so") {
		if (canMove(x, y + 1) && (isPC || (getTileState(x, y + 1) == '.'))) {
			setTileCTop(x, y + 1, &c);
			setTileCTop(x, y, nullptr);
			c.setY(y + 1);
            if(isPC) {
                actions += "PC moves south. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	} else if (s == "sw") {
		if (canMove(x - 1, y + 1) && (isPC || (getTileState(x - 1, y + 1) == '.'))) {
			setTileCTop(x - 1, y + 1, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x - 1);
			c.setY(y + 1);
            if(isPC) {
                actions += "PC moves southwest. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	}else if (s == "we") {
		if (canMove(x - 1, y) && (isPC || (getTileState(x - 1, y) == '.'))) {
			setTileCTop(x - 1, y, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x - 1);
            if(isPC) {
                actions += "PC moves west. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }

	}else if (s == "nw") {
		if (canMove(x - 1, y - 1) && (isPC || (getTileState(x - 1, y - 1) == '.'))) {
			setTileCTop(x - 1, y - 1, &c);
			setTileCTop(x, y, nullptr);
			c.setX(x - 1);
			c.setY(y - 1);
            if(isPC) {
                actions += "PC moves northwest. ";
                seePotions(c);
            }
		} else {
            if(isPC) {
                actions += "Cannot move there. ";
            }
        }
	} else {
        actions += "Please enter valid direction. ";
    }
    x = c.getX();
    y = c.getY();



if(isPC && (getTileITop(x,y)) && (getTileITop(x, y)->getState() == 'G') && ((getTileITop(x, y)->getCanTake()))) {
    actions = actions + "Player picked up " + std::to_string((getTileITop(x,y)->getValue())) + " pieces of gold. ";
    PC->addGold(getTileITop(x,y)->getValue());
    delete getTileITop(x,y);
    setTileITop(x,y, nullptr);
}
}

void Grid::NPCMove(bool freeze) {
	for(int i = 0; i < enemies.size(); ++i) {
		bool attacked = false;
		if ((enemies[i]->getRace() != "Merchant") || (Merchant::gethostile)) {
			attacked = checkAttack(*(enemies[i]), enemies[i]->getX(), enemies[i]->getY());
			if ((enemies[i]->getRace() == "Dragon") && !attacked) {
				attacked = checkAttack(*(enemies[i]), enemies[i]->goldX(), enemies[i]->goldY());
			}

		}
		if (!freeze) {
		if (!attacked) {
			if (enemies[i]->getRace() != "Dragon") {
			int move_dir = rand() % 8;
			if (move_dir == 0) charMove(*enemies[i], "no");
			else if (move_dir == 1) charMove(*enemies[i], "ne");
			else if (move_dir == 2) charMove(*enemies[i], "ea");
			else if (move_dir == 3) charMove(*enemies[i], "se");
			else if (move_dir == 4) charMove(*enemies[i], "so");
			else if (move_dir == 5) charMove(*enemies[i], "sw");
			else if (move_dir == 6) charMove(*enemies[i], "we");
			else if (move_dir == 7) charMove(*enemies[i], "nw");
		}
		}
		}
	}

}

void Grid::printMap() {
	for(int i = 0; i < 25; ++i) {
		for(int h = 0; h < 79; ++h) {
			map[i][h].print();
		}
		std::cout << std::endl;
	}
std::cout << "Race: " << PC->getRace() << "   Gold: " << PC->getGold() << "                    Level: " << level << std::endl;
std::cout << "HP: " << PC->getHp() << std::endl;
std::cout << "ATK: " << PC->getAtk() << std::endl;
std::cout << "DEF: " << PC->getDef() << std::endl;
std::cout << actions << std::endl;
actions = " ";
}
