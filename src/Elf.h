#ifndef _ELF_H
#define _ELF_H
#include "NPC.h"

class Elf : public NPC{
 public:
  Elf();
  void Attack(std::string &out, Character &c);
};

#endif
