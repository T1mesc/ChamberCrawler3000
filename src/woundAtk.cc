#include "Character.h"
#include "woundAtk.h"

bool woundAtk::identified = false;

void woundAtk::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a WA Potion. ";
  if (c.getRace() == "Drow"){
	c.setAtk(c.getAtk() - 7.5);
  }
  else{
 	c.setAtk(c.getAtk() - 5);
  }
}

void woundAtk::print(std::string &out){
	if (identified){
		out += "a WA Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}
