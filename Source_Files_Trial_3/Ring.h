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
   string name;
   Ring(bool equippedValue, int enchantBonus);
   explicit Ring(int enchantBonus);
   Ring();

   void getRandomEnchantment() override;
};


#endif