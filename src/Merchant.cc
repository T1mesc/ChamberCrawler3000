#include "Merchant.h"

bool Merchant::hostile = false;

Merchant::Merchant(): NPC("Merchant"){ 
}

void Merchant::Attack(std::string &out, Character &c){
  if (gethostile()){
    if (rand() % 2 == 0){
      out = out + getRace() + " misses Player. ";
  	  return;
  	}
  	c.setHp(c.getHp() - calculateDamage(getAtk(), c.getDef()));
    out = out + getRace() + " deals " +
    std::to_string(calculateDamage(getAtk(), c.getDef())) + " damage to Player(" + 
 std::to_string(c.getHp()) + "). ";
  }
}


void Merchant::sethostile(bool h) {
	hostile = h;

}

bool Merchant::gethostile() {
	return hostile;
}

