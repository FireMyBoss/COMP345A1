#include "Shield.h"
#include <cstdlib>
#include <string>

string Shield::listOfEnchantments[] = {"Armor class"};

Shield::Shield(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Shield") {
    string enchantType = Shield::getRandomEnchantment();
    setEnchantment(enchantType);
}
Shield::Shield(int enchantBonus) : Equipment(enchantBonus), name("Shield") {
    string enchantType = Shield::getRandomEnchantment();
    setEnchantment(enchantType);
}
Shield::Shield() : name("Shield"){
    string enchantType = Shield::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Shield::getRandomEnchantment(){
    return listOfEnchantments[0];
}
