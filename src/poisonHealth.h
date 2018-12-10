#ifndef _POSIONHEALTH_H_
#define _POSIONHEALTH_H_
#include "Potion.h"

class poisonHealth : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};

#endif
