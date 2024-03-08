#include "Belt.h"
#include <cstdlib>
#include <string>

string Belt::listOfEnchantments[] = {"Constitution", "Strength"};

Belt::Belt(){
    Belt::getRandomEnchantment();
    setRandBonus();
    itmName = "Belt";
}

void Belt::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 2]);
}
