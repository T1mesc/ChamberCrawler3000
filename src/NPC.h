#ifndef _NPC_H
#define _NPC_H
#include "Character.h"
#include <iostream>

class NPC : public Character{
 public:
  NPC(std::string Race);
  virtual void Attack(std::string &out, Character &c);
  virtual int goldX();
  virtual int goldY();
};

#endif
