#include "Boots.h"
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
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 2]);
}
