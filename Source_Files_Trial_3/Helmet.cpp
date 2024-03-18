#include "Helmet.h"
#include "misc.h"

#include <cstdlib>
#include <string>

string Helmet::listOfEnchantments[] = {"Intelligence", "Wisdom", "Armor class"};


Helmet::Helmet(){
    Helmet::getRandomEnchantment();
    setRandBonus();
    itmName = "Helmet";
}

void Helmet::getRandomEnchantment(){


    setEnchantment(listOfEnchantments[getCurrentTime() % 3]);
}
