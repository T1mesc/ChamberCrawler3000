#include "grid.h"
#include "Character.h"
#include <iostream>
#include <string>
#include <ctime>
#include <stdlib.h>
#include "PC.h"
#include "Shade.h"
#include "Goblin.h"
#include "Drow.h"
#include "Vampire.h"
#include "Troll.h"

int main() {
	srand(time(NULL));
	std::string s;
	bool restart = false;
	bool freeze = false;
	Character * sh = nullptr;
	while(1) {
		delete sh;
		restart = false;
		freeze = false;
		system("clear");
		std::cout << "This is a C++ group project." << std::endl;
		std::cout << "Creators: Yidong Liu, Denis Karch, Churan Chen" << std::endl;
		std::cout << "Choose your character! - s(shade), d(drow), g(goblin), v(vampire), t(troll). Default character is Shade." << std::endl;
		std::cin >> s;
		if (s == "d") {;
			sh = new Drow;
		} else if (s == "g") {
			sh = new Goblin;
		} else if (s == "v") {
			sh = new Vampire;
		} else if (s == "t") {
			sh = new Troll;
		} else {
			sh = new Shade;
		}
		for (int i = 1; i <= 5; ++i) {
		Grid g(sh, i);
		g.printMap();
		std::cout << "Adventure time! Will you move, attack, use a potion, freeze enemies, restart the game, or admit defeat?" << std::endl;
		while(1) {
			std::cin >> s;

			if (s == "q") {
				std::cout << "Admitted defeat?" << std::endl;
				delete sh;
				return 0;
			} else if (s == "r") {
				std::cout << "Restarting game." << std::endl;
				restart = true;
				break;
			}
			else if (s == "f") {
				if (freeze) freeze = false;
				if (!freeze) freeze = true;
			}
			else if (s == "a") {
				std::cin >> s;
				if (s == "no") { 
					g.charAttack(*sh, sh->getX(), sh->getY() -1);
				} else if (s == "ne") {
					g.charAttack(*sh, sh->getX() + 1, sh->getY() - 1);
				} else if (s == "ea") {
					g.charAttack(*sh, sh->getX() + 1, sh->getY());
				} else if (s == "se") {
					g.charAttack(*sh, sh->getX() + 1, sh->getY() + 1);
				} else if (s == "so") {
					g.charAttack(*sh, sh->getX(), sh->getY() + 1);
				} else if (s == "sw") {
					g.charAttack(*sh, sh->getX() - 1, sh->getY() + 1);
				} else if (s == "we") {
					g.charAttack(*sh, sh->getX() - 1, sh->getY());
				} else if (s == "nw") {
					g.charAttack(*sh, sh->getX() - 1, sh->getY() - 1);
				}
			}
			else if (s == "u") {
				std::cin >> s;
			if (s == "no") { 
					g.charDrink(*sh, sh->getX(), sh->getY() -1);
				} else if (s == "ne") {
					g.charDrink(*sh, sh->getX() + 1, sh->getY() - 1);
				} else if (s == "ea") {
					g.charDrink(*sh, sh->getX() + 1, sh->getY());
				} else if (s == "se") {
					g.charDrink(*sh, sh->getX() + 1, sh->getY() + 1);
				} else if (s == "so") {
					g.charDrink(*sh, sh->getX(), sh->getY() + 1);
				} else if (s == "sw") {
					g.charDrink(*sh, sh->getX() - 1, sh->getY() + 1);
				} else if (s == "we") {
					g.charDrink(*sh, sh->getX() - 1, sh->getY());
				} else if (s == "nw") {
					g.charDrink(*sh, sh->getX() - 1, sh->getY() - 1);
				}
			}
			else {
				g.charMove(*sh, s);
			}
			if (sh->Die()) {
				std::cout << "You died! Game over!" << std::endl;
				delete sh;
				return 0;
			} if (g.getTileState(sh->getX(), sh->getY()) == '\\') {
				if (i == 5) {
					int n = 0;
					if (sh->getRace() == "Vampire") {
						n = 1.5 * sh->getGold();
					} else {
						n = sh->getGold();
					}
					delete sh;
					std::cout << "You completed the game! Your score is " << n << std:: endl;
					return 0;
				}
				std::cout << "You've advance a level!" << std::endl;
				break;
			}
			system("clear");
			g.NPCMove(freeze);
			g.printMap();


		}
		if(restart) break;
	}

	}
}
