#include "Helmet.h"
#include <cstdlib>
#include <string>

string Helmet::listOfEnchantments[] = {"Intelligence", "Wisdom", "Armor class"};

Helmet::Helmet(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Helmet") {
    Helmet::getRandomEnchantment();
}
Helmet::Helmet(int enchantBonus) : Equipment(enchantBonus), name("Helmet") {
    Helmet::getRandomEnchantment();
}
Helmet::Helmet() : name("Helmet"){
    Helmet::getRandomEnchantment();
    setRandBonus();
}

void Helmet::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 3]);
}
