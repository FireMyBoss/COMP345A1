#include "Ring.h"
#include <cstdlib>
#include <string>

string Ring::listOfEnchantments[] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charismas"};

Ring::Ring(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = Ring::getRandomEnchantment();
    setEnchantment(enchantType);
}
Ring::Ring(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = Ring::getRandomEnchantment();
    setEnchantment(enchantType);
}
Ring::Ring(){
    string enchantType = Ring::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Ring::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 5];
}
