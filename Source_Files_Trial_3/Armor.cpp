#include "Armor.h"
#include <cstdlib>
#include <string>

string Armor::listOfEnchantments[] = {"Armor class"};

Armor::Armor(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Armor") {
    Armor::getRandomEnchantment();
}
Armor::Armor(int enchantBonus) : Equipment(enchantBonus), name("Armor") {
    Armor::getRandomEnchantment();
}
Armor::Armor() : name("Armor"){
    Armor::getRandomEnchantment();
    setRandBonus();
    
}

void Armor::getRandomEnchantment(){
    setEnchantment(listOfEnchantments[0]);
}
