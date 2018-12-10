#include "Orc.h"

Orc::Orc(): NPC("Orc"){}


void Orc::Attack(std::string &out, Character &c){
  if (rand()%2 == 0){
    out = out + getRace() + " misses Player. ";
  	return;
  }
  if (c.getRace() == "Goblin"){
    c.setHp(c.getHp() - 1.5*calculateDamage(getAtk(), c.getDef()));
out = out + "Orc deals " + 
    std::to_string(1.5 *calculateDamage(getAtk(), c.getDef())) + " damage to Player(" + 
 std::to_string(c.getHp()) + "). ";
    return;
} else {
c.setHp(c.getHp() - calculateDamage(getAtk(), c.getDef()));
    out = out + "Orc deals " + 
    std::to_string(calculateDamage(getAtk(), c.getDef())) + " damage to Player(" + 
 std::to_string(c.getHp()) + "). ";
    return;
  }
}
