#ifndef _DRAGON_H
#define _DRAGON_H
#include "NPC.h"

class Dragon : public NPC{
  int gx;
  int gy;
 public:
  Dragon(int x, int y);
  int goldX();
  int goldY();
};

#endif
