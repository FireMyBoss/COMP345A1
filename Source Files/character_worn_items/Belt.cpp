#include "Belt.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Constitution", "Strength"};

Belt::Belt(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Belt::Belt(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Belt::Belt(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Belt::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
