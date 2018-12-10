#include "PC.h"

PC::PC(std::string Race): Character(Race){}

int PC::getScore(){
	if (Race == "Shade") return 1.5*Gold;
	else return Gold;
}

void PC::Attack(std::string &out, Character &c){
  if (c.getRace() == "Halfling"){
    if (rand()%2 == 0){
      out = out + "Player misses " + c.getRace() + ". ";
      return;
    }
  }
  if (c.getRace() == "Merchant"){
    Merchant::sethostile(true);
  }
  c.setHp(c.getHp() - calculateDamage(getAtk(), c.getDef()));
  out = out + "Player deals " + 
    std::to_string(calculateDamage(getAtk(), c.getDef())) + " damage to " + c.getRace() + "(" + 
 std::to_string(c.getHp()) + "). ";
  if (c.getHp() <= 0 && c.getRace() != "Human" && c.getRace() != "Merchant" && c.getRace() != "Dragon"){
    addGold(rand() % 2 + 1);
  }
}


 int PC::goldX() {return 1;}
 int PC::goldY() {return 1;}

