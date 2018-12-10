#ifndef _WOUNDDEF_H_
#define _WOUNDDEF_H_
#include "Potion.h"

class woundDef : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};

#endif
