#include "Elf.h"

Elf::Elf(): NPC("Elf"){}

void Elf::Attack(std::string &out, Character &c){
  for (int i = 0; i < 2; ++i){
    if (rand() % 2 == 0){
   out = out + getRace() + " misses Player" + ". ";
  	  continue;
  	}
  	c.setHp(c.getHp() - calculateDamage(getAtk(), c.getDef()));
    out = out + getRace() + " deals " + 
    std::to_string(calculateDamage(getAtk(), c.getDef())) + " damage to Player(" + 
 std::to_string(c.getHp()) + "). ";
  	if (c.getRace() == "Drow") break;
  }
}



