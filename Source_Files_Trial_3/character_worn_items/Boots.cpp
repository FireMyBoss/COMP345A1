#include "Boots.h"
#include <cstdlib>
#include <string>

string Boots::listOfEnchantments[] = {"Armor class", "Dexterity"};

Boots::Boots(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Boots::Boots(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Boots::Boots(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Boots::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
