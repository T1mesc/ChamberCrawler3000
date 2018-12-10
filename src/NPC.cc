#include "NPC.h"

NPC::NPC(std::string Race): Character(Race){}

void NPC::Attack(std::string &out, Character &c){
  
  if (rand() % 2 == 0){
  out = out + getRace() + " misses Player. ";
    return;
  }
  c.setHp(c.getHp() - calculateDamage(getAtk(), c.getDef()));
    out = out + getRace() + " deals " +
    std::to_string(calculateDamage(getAtk(), c.getDef())) + " damage to Player(" + 
 std::to_string(c.getHp()) + "). ";
}

int NPC::goldX() { return 1; }
int NPC::goldY() { return 1; }


