#include "Character.h"

Character::Character() {}

Character::Character(std::string Race) : Race(Race){
  if (Race == "Shade"){
    Hp = 125;
    max_Hp = 125;
    Atk = 25;
    Def = 25;
  }
  else if (Race == "Drow"){
    Hp = 150;
    max_Hp = 150;
    Atk = 25;
    Def = 15;
  }
  else if (Race == "Vampire"){
    Hp = 50;
    Atk = 25;
    Def = 25;
  }
  else if (Race == "Troll"){
    Hp = 120;
    max_Hp = 120;
    Atk = 25;
    Def = 15;
  }
  else if (Race == "Goblin"){
    Hp = 110;
    max_Hp = 110;
    Atk = 15;
    Def = 20;
  }
  else if (Race == "Human"){
    state = 'H';
    Hp = 140;
    max_Hp = 140;
    Atk = 20;
    Def = 20;
  }
  else if (Race == "Dwarf"){
    state = 'W';
    Hp = 100;
    max_Hp = 100;
    Atk = 20;
    Def = 30;
  }
  else if (Race == "Elf"){
    state = 'E';
    Hp = 140;
    max_Hp = 140;
    Atk = 30;
    Def = 10;
  }
  else if (Race == "Orc"){
    state = 'O';
    Hp = 180;
    max_Hp = 180;
    Atk = 30;
    Def = 25;
  }
  else if (Race == "Merchant"){
    state = 'M';
    Hp = 30;
    max_Hp = 30;
    Atk = 70;
    Def = 5;
  }
  else if (Race == "Dragon"){
    state = 'D';
    Hp = 150;
    max_Hp = 150;
    Atk = 20;
    Def = 20;
  }
  else if (Race == "Halfling"){
    state = 'L';
    Hp = 100;
    max_Hp = 100;
    Atk = 15;
    Def = 20;
  }
  if (state == ' ') state = '@';
Gold = 0;
}



int Character::calculateDamage(int atk, int def){
  return ceil((100*atk/(100+def)));
}

std::string Character::getRace(){
  return Race;
}

int Character::getHp(){
  return Hp;
}

void Character::setHp(int points){
  Hp = points;
  if (Hp < 0) Hp = 0;
  if ((Hp > max_Hp) && (Race != "Vampire")) Hp = max_Hp;

}

int Character::getAtk(){
  return Atk;
}

void Character::setAtk(int Atk){
  this->Atk = Atk;
}

int Character::getDef(){
  return Def;
}

void Character::setDef(int Def){
  this->Def = Def;
}

int Character::getGold(){
  return Gold;
}

void Character::addGold(int Gold){
  this->Gold += Gold;
}

char Character::getState() {
  return state;
}

int Character::getX() {
  return loc_x;
}

int Character::getY() {
  return loc_y;
}

void Character::setX(int x) {
  loc_x = x;
}

void Character::setY(int y) {
  loc_y = y;
}

bool Character::Die(){
  if (Hp <= 0) return true;
	return false;
}

void Character::reset(){}

//void Character::Drink(Potion &p){}


