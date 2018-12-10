#include "Character.h"
#include "woundDef.h"

bool woundDef::identified = false;

void woundDef::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a WD Potion. ";
  if (c.getRace() == "Drow"){
	c.setDef(c.getDef() - 7.5);
  }
  else{
 	c.setDef(c.getDef() - 5);
  }
}

void woundDef::print(std::string &out){
	if (identified){
		out += "a WD Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}
