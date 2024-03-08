#ifndef Boots_h
#define Boots_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Boots : public Equipment{
private:
   static string listOfEnchantments[2];
public:
   string name;
   Boots(bool equippedValue, int enchantBonus);
   Boots(int enchantBonus);
   Boots();

   string getRandomEnchantment();
};


#endif