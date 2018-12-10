#include "tile.h"
#include <iostream>

Tile::Tile() {
	state = ' ';
	charTop = nullptr;
	itemTop = nullptr;

}

Tile::~Tile() {
	delete itemTop;
}

bool Tile::isEmpty() {
  if((state == '.') && (!itemTop) && (!charTop)) return true;
  return false;
}

char Tile::getState() {
	return state;
}

Character *Tile::getCharTop() {
	return charTop;
}

Item *Tile::getItemTop() {
	return itemTop;
}

void Tile::setState(char s) {
	state = s;
}

void Tile::setCharTop(Character *c) {
	charTop = c;
}

void Tile::setItemTop(Item *i) {
	itemTop = i;
}

void Tile::print() {
	if(charTop) { 
		std::cout << charTop->getState();
	} else if (itemTop) {
		std::cout << itemTop->getState();
	} else {
		std::cout << state;
	}
}

bool Tile::canMove() {
	if (!(charTop) && ((!itemTop) || (itemTop->getState() == 'G')) &&
		((state == '.') || (state == '#') || (state == '+') || (state == '\\'))) {
		return true;
	}
	return false;
}

bool Tile::ifDead(std::string &out, Character &c) {
	if (charTop->Die()) {
		if((charTop->getRace() == "Merchant") ||
		   (charTop->getRace() == "Human")) {
			itemTop = new Gold(4);
			out = out + "PC killed a " + charTop->getRace() + ". ";

		} else if (charTop->getRace() == "Dragon") {
			out = out +"PC killed a " + charTop->getRace() + ". ";
		} else if ((charTop->getRace() == "Dwarf") ||
		           (charTop->getRace() == "Elf") ||
		           (charTop->getRace() == "Orc") ||
		           (charTop->getRace() == "Halfing")){
			out = out + "PC killed a " + charTop->getRace() + ". ";
		}
	return true;

	}
	return false;
}
