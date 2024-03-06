#ifndef Weapon_h
#define Weapon_h

#include <string>
#include <stdio.h>
#include "Equipment.h"

using namespace std;

class Weapon : public Equipment{
private:
   static string listOfEnchantments[2];
public:
   Weapon(bool equippedValue, int enchantBonus);
   explicit Weapon(int enchantBonus);
   Weapon();

   string getRandomEnchantment();
};


#endif