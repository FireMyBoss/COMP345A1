#include "Ring.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charismas"};

Ring::Ring(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Ring::Ring(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Ring::Ring(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Ring::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 5];
}
