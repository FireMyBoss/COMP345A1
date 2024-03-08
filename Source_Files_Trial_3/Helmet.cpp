#include "Helmet.h"
#include <cstdlib>
#include <string>

string Helmet::listOfEnchantments[] = {"Intelligence", "Wisdom", "Armor class"};

Helmet::Helmet(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = Helmet::getRandomEnchantment();
    setEnchantment(enchantType);
}
Helmet::Helmet(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = Helmet::getRandomEnchantment();
    setEnchantment(enchantType);
}
Helmet::Helmet(){
    string enchantType = Helmet::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Helmet::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 3];
}
