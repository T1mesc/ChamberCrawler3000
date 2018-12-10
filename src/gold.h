#ifndef _GOLD_H_
#define _GOLD_H_
#include "item.h"

class Gold : public Item {
	int value;
bool canTake;
public:
	Gold(int n);
	int getValue();
	void setValue(int n);

bool getCanTake();
void setCanTake(bool b);
};

#endif 
