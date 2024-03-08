#include "Armor.h"
#include <cstdlib>
#include <string>

string Armor::listOfEnchantments[] = {"Armor class"};

Armor::Armor(){
    Armor::getRandomEnchantment();
    setRandBonus();
    itmName = "Armor";
    
}

void Armor::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[0]);
}
