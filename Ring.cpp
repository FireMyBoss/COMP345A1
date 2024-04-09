#include "Ring.h"
#include <cstdlib>
#include <string>

string Ring::listOfEnchantments[] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charismas"};

Ring::Ring(){
    Ring::getRandomEnchantment();
    setRandBonus();
    itmName = "Ring";
}

void Ring::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[rand() % 5]);
}
