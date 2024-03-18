#include "Belt.h"
#include "misc.h"

#include <cstdlib>
#include <string>

string Belt::listOfEnchantments[] = {"Constitution", "Strength"};

Belt::Belt(){
    Belt::getRandomEnchantment();
    setRandBonus();
    itmName = "Belt";
}

void Belt::getRandomEnchantment(){

    setEnchantment(listOfEnchantments[getCurrentTime() % 2]);
    
}
