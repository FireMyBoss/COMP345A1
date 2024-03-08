#include "Ring.h"
#include <cstdlib>
#include <string>

string Ring::listOfEnchantments[] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charismas"};

Ring::Ring(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Ring") {
    Ring::getRandomEnchantment();
}
Ring::Ring(int enchantBonus) : Equipment(enchantBonus), name("Ring") {
    Ring::getRandomEnchantment();
}
Ring::Ring() : name("Ring"){
    Ring::getRandomEnchantment();
    setRandBonus();
}

void Ring::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 5]);
}
