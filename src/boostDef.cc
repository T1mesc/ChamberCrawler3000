#include "Character.h"
#include "boostDef.h"

bool boostDef::identified = false;

void boostDef::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a BD Potion. ";
  if (c.getRace() == "Drow"){
	c.setDef(c.getDef() + 7.5);
  }
  else{
 	c.setDef(c.getDef() + 5);
  }
}


void boostDef::print(std::string &out){
	if (identified){
		out += "a BD Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}
