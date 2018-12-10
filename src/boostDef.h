#ifndef _BOOSTDEF_H_
#define _BOOSTDEF_H_
#include "Potion.h"

class boostDef : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};

#endif
