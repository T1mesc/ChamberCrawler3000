#ifndef _MERCHANT_H
#define _MERCHANT_H
#include "NPC.h"

class Merchant : public NPC{
  static bool hostile;
 public:
  Merchant();
  static void sethostile(bool h);
  static bool gethostile();
  void Attack(std::string &out, Character &c);
};

#endif
