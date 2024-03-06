#ifndef Belt_h
#define Belt_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Belt : public Equipment{
private:
   static string listOfEnchantments[2];
public:
   Belt(bool equippedValue, int enchantBonus);
   Belt(int enchantBonus);
   Belt();
   ~Belt();

   string getRandomEnchantment();
};


#endif