#ifndef _CHARACTER_H
#define _CHARACTER_H
#include <string>
#include <math.h>

class Character {
 protected:
  std::string Race;
  char state = ' ';
  int loc_x;
  int loc_y;
  int Hp;
  int max_Hp;
  int Atk;
  int Def;
  int Gold;
 public:
  static int calculateDamage(int atk, int def);
  Character();
  Character(std::string Race);
  std::string getRace();
  int getHp();
  void setHp(int Hp);
  int getAtk();
  void setAtk(int Atk);
  int getDef();
  void setDef(int Def);
  int getGold();
  void addGold(int Gold);

  char getState(); // getters
  int getX();
  int getY();
  void setX(int x); // setters
  void setY(int y);

  virtual int goldX() = 0;
  virtual int goldY() = 0;
  bool Die();
  virtual void reset();
  //virtual void Drink(Potion &p);
  virtual void Attack(std::string &out, Character &c) = 0;
};

#endif
