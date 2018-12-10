#include "Goblin.h"
#include "Merchant.h"

Goblin::Goblin(): PC("Goblin"){}

void Goblin::reset(){
  Atk = 15;
  Def = 20;
}

void Goblin::Attack(std::string &out, Character &c){
	if (c.getRace() == "Halfling"){
		if (rand()%2 == 0){
      		out = out + "Player misses" + c.getRace() + ". ";
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
	if (c.getHp() <= 0) addGold(5);
}
