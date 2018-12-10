#ifndef _BOOSTATK_H_
#define _BOOSTATK_H_
#include "Potion.h"

class boostAtk : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};

#endif
