#include "Character.h"
#include "poisonHealth.h"

bool poisonHealth::identified = false;

void poisonHealth::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a PH Potion. ";
  if (c.getRace() == "Drow"){
	c.setHp(c.getHp() - 1.5*(rand()%10));
  }
  else{
	c.setHp(c.getHp() - rand()%10);
  }
}

void poisonHealth::print(std::string &out){
	if (identified){
		out += "a PH Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}

