#ifndef Ring_h
#define Ring_h

#include <string>
#include <stdio.h>

#include "misc.h"
#include "Equipment.h"

using namespace std;

class Ring : public Equipment{
private:
   static string listOfEnchantments[5];
public:
   Ring();

   void getRandomEnchantment() override;
};


#endif
