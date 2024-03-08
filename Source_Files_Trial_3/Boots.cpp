#include "Boots.h"
#include <cstdlib>
#include <string>

string Boots::listOfEnchantments[] = {"Armor class", "Dexterity"};

Boots::Boots(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Boots") {
    Boots::getRandomEnchantment();
}
Boots::Boots(int enchantBonus) : Equipment(enchantBonus), name("Boots") {
    Boots::getRandomEnchantment();
}
Boots::Boots() : name("Boots"){
    Boots::getRandomEnchantment();
    setRandBonus();
}

void Boots::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 2]);
}
