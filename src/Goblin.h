#ifndef _GOBLIN_H
#define _GOBLIN_H
#include "PC.h"

class Goblin : public PC{
 public:
  Goblin();
  void reset();
  void Attack(std::string &out, Character &c) override;
};

#endif
