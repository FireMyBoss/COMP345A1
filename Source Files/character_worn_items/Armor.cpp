#include "Armor.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Armor class"};

Armor::Armor(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Armor::Armor(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Armor::Armor(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Armor::getRandomEnchantment(){
    return listOfEnchantments[0];
}
