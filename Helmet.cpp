#include "Helmet.h"
#include <cstdlib>
#include <string>

string Helmet::listOfEnchantments[] = {"Intelligence", "Wisdom", "Armor class"};


Helmet::Helmet(){
    Helmet::getRandomEnchantment();
    setRandBonus();
    itmName = "Helmet";
}

void Helmet::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[rand() % 3]);
}
