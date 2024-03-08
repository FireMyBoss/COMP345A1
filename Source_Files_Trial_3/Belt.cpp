#include "Belt.h"
#include <cstdlib>
#include <string>

string Belt::listOfEnchantments[] = {"Constitution", "Strength"};

Belt::Belt(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Belt") {
    string enchantType = Belt::getRandomEnchantment();
    setEnchantment(enchantType);
}
Belt::Belt(int enchantBonus) : Equipment(enchantBonus), name("Belt") {
    string enchantType = Belt::getRandomEnchantment();
    setEnchantment(enchantType);
}
Belt::Belt() : name("Belt"){
    string enchantType = Belt::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Belt::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
