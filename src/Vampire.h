#ifndef _VAMPIRE_H
#define _VAMPIRE_H
#include "PC.h"
#include "Merchant.h"

class Vampire : public PC{
 public:
  Vampire();
  void reset();
  void Attack(std::string &out, Character &c);
};

#endif
