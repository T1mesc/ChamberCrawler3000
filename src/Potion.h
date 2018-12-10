#ifndef _POTION_H_
#define _POTION_H_
#include <cstdlib>
#include <string>
#include "item.h"
#include "Character.h"

class Potion : public Item {
 public:
  Potion();
  virtual void Affect(std::string &out, Character &c) = 0;
  virtual void print(std::string &out) = 0;
};

#endif
