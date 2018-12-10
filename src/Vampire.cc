#include "Vampire.h"

Vampire::Vampire(): PC("Vampire"){}

void Vampire::reset(){
  Atk = 25;
  Def = 25;
}

void Vampire::Attack(std::string &out, Character &c){
  if (c.getRace() == "Halfling"){
    if (rand()%2 == 0){
      out = out + "Player misses" + c.getRace() + ". ";
      return;
    }
  }
  if (c.getRace() == "Dwarf"){
    setHp(getHp() - 5);
  }
  else{
    setHp(getHp() + 5);
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

