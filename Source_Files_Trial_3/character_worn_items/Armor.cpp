#include "Armor.h"
#include <cstdlib>
#include <string>

string Armor::listOfEnchantments[] = {"Armor class"};

Armor::Armor(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = Armor::getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = Armor::getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor(){
    string enchantType = Armor::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Armor::getRandomEnchantment(){
    return listOfEnchantments[0];
}
