#ifndef Ring_h
#define Ring_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Ring : public Equipment{
private:
   static string listOfEnchantments[5];
public:
   Ring(bool equippedValue, int enchantBonus);
   Ring(int enchantBonus);
   Ring();
   ~Ring();

   string getRandomEnchantment();
};


#endif