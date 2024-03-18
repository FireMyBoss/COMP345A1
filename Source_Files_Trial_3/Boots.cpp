#include "Boots.h"
#include "misc.h"

#include <cstdlib>
#include <string>
#include <iostream>

string Boots::listOfEnchantments[] = {"Armor class", "Dexterity"};

Boots::Boots(){
    Boots::getRandomEnchantment();
    setRandBonus();
    itmName = "Boots";
}

void Boots::getRandomEnchantment(){

    setEnchantment(listOfEnchantments[getCurrentTime() % 2]);
    
}
