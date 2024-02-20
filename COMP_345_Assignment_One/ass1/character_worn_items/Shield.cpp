#include "Shield.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Armor class"};

Shield::Shield(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Shield::Shield(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Shield::Shield(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Shield::getRandomEnchantment(){
    return listOfEnchantments[0];
}
