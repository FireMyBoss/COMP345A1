#include "Boots.h"
#include <cstdlib>
#include <string>

string Boots::listOfEnchantments[] = {"Armor class", "Dexterity"};

Boots::Boots(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = Boots::getRandomEnchantment();
    setEnchantment(enchantType);
}
Boots::Boots(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = Boots::getRandomEnchantment();
    setEnchantment(enchantType);
}
Boots::Boots(){
    string enchantType = Boots::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Boots::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
