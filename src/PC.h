#ifndef _PC_H
#define _PC_H
#include "Character.h"
#include <string>
#include "Merchant.h"
#include <cmath>
#include <iostream>

class PC : public Character {
 public:
  PC(std::string Race);
  int getScore();
  virtual void reset() = 0;
  virtual void Attack(std::string &out, Character &c);
  virtual int goldX();
  virtual int goldY();
};
#endif
