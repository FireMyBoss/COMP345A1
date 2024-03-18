#include "Weapon.h"
#include "misc.h"

#include <cstdlib>
#include <string>

string Weapon::listOfEnchantments[] = {"Attack bonus", "Damage bonus"};


Weapon::Weapon(){
    Weapon::getRandomEnchantment();
    setRandBonus();
    itmName = "Weapon";
}

void Weapon::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[getCurrentTime() % 2]);
}
