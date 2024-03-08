#include "Shield.h"
#include <cstdlib>
#include <string>

string Shield::listOfEnchantments[] = {"Armor class"};

Shield::Shield(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Shield") {
    Shield::getRandomEnchantment();
}
Shield::Shield(int enchantBonus) : Equipment(enchantBonus), name("Shield") {
    Shield::getRandomEnchantment();
}
Shield::Shield() : name("Shield"){
    Shield::getRandomEnchantment();
    setRandBonus();
}

void Shield::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[0]);
}
