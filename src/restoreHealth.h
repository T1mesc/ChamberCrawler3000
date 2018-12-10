#ifndef _RESTOREHEALTH_H_
#define _RESTOREHEALTH_H_
#include "Potion.h"

class restoreHealth : public Potion {
  static bool identified;
 public:
  void Affect(std::string &out, Character &c);
  void print(std::string &out);
};


#endif
