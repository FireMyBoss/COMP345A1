#include "Armor.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Armor class"};

Armor::Armor(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Armor::getRandomEnchantment(){
    return listOfEnchantments[0];
}
