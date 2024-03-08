#ifndef Equipment_h
#define Equipment_h

#include <string>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Equipment : public Item{
protected:

public:
    Equipment() {Equipment::setRandBonus();};
    void setRandBonus(); //if enchantmentType != null, gets a random bonus between 1-5
 
};


#endif