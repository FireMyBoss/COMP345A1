#include "Helmet.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Intelligence", "Wisdom", "Armor class"};

Helmet::Helmet(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Helmet::Helmet(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Helmet::Helmet(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Helmet::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 3];
}
