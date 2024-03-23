#include "Shield.h"
#include <cstdlib>
#include <string>

string Shield::listOfEnchantments[] = {"Armor class"};

Shield::Shield(){
    Shield::getRandomEnchantment();
    setRandBonus();
    itmName = "Shield";
}

void Shield::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[0]);
}
