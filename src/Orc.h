#ifndef _ORC_H
#define _ORC_H
#include "NPC.h"

class Orc : public NPC{
 public:
  Orc();
  void Attack(std::string &out, Character &c);
};

#endif
