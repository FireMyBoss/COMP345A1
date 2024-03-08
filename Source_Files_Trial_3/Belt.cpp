#include "Belt.h"
#include <cstdlib>
#include <string>

string Belt::listOfEnchantments[] = {"Constitution", "Strength"};

Belt::Belt(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Belt") {
    Belt::getRandomEnchantment();
}
Belt::Belt(int enchantBonus) : Equipment(enchantBonus), name("Belt") {
    Belt::getRandomEnchantment();
}
Belt::Belt() : name("Belt"){
    Belt::getRandomEnchantment();
    setRandBonus();
}

void Belt::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 2]);
}
