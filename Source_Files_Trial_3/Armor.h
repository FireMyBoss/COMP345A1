#ifndef Armor_h
#define Armor_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Armor : public Equipment{
private:
   static string listOfEnchantments[1];
public:
   string name;
   Armor(bool equippedValue, int enchantBonus);
   Armor(int enchantBonus);
   Armor();

   void getRandomEnchantment();
};


#endif