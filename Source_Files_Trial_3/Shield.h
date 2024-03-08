#ifndef Shield_h
#define Shield_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Shield : public Equipment{
private:
   static string listOfEnchantments[1];
public:
   string name;
   Shield(bool equippedValue, int enchantBonus);
   explicit Shield(int enchantBonus);
   Shield();

   void getRandomEnchantment();
};


#endif