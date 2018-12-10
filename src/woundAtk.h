#ifndef _WOUNDATK_H_
#define _WOUNDATK_H_
#include "Potion.h"

class woundAtk : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};

#endif
