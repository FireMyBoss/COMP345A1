#include "Shield.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Armor class"};

Shield::Shield(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Shield::Shield(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Shield::Shield(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Shield::getRandomEnchantment(){
    return listOfEnchantments[0];
}
