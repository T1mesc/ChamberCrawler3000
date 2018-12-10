#include "Character.h"
#include "restoreHealth.h"

bool restoreHealth::identified = false;

void restoreHealth::Affect(std::string &out, Character &c){
  identified = true;
  out += "Player drinks a RH Potion. ";
  if (c.getRace() == "Drow"){
	c.setHp(c.getHp() + 1.5*(rand()%10));
  }
  else{
	c.setHp(c.getHp() + rand()%10);
  }
}

void restoreHealth::print(std::string &out){
	if (identified){
		out += "a RH Potion. ";
	}
	else{
		out += "an unidentified potion. ";
	}
}
