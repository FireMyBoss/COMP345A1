#ifndef Boots_h
#define Boots_h

#include <string>
#include <stdio.h>

#include "misc.h"
#include "Equipment.h"

using namespace std;

class Boots : public Equipment{
private:
   static string listOfEnchantments[2];
public:
   Boots();

   void getRandomEnchantment();
};


#endif
