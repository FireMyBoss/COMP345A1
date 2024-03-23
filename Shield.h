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
   Shield();

   void getRandomEnchantment();
};


#endif