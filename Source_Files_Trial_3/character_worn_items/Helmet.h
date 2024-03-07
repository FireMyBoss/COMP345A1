#ifndef Helmet_h
#define Helmet_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Helmet : public Equipment{
private:
   static string listOfEnchantments[3];
public:
   Helmet(bool equippedValue, int enchantBonus);
   Helmet(int enchantBonus);
   Helmet();

   string getRandomEnchantment();
};



#endif