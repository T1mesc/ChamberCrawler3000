#include "Character.h"
#include "boostAtk.h"

bool boostAtk::identified = false;

void boostAtk::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a BA Potion. ";
  if (c.getRace() == "Drow"){
	c.setAtk(c.getAtk() + 7.5);
  }
  else{
 	c.setAtk(c.getAtk() + 5);
  }
}

void boostAtk::print(std::string &out){
	if (identified){
		out += "a BA Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}
