#ifndef _ITEM_H_
#define _ITEM_H_
#include <string>


class Item {
	char state;
public:
	Item();
	char getState();
	void setState(char c);
	virtual void setValue(int n);
	virtual int getValue();
virtual bool getCanTake();
virtual void setCanTake(bool b);

	
};

#endif
