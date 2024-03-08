#include "Armor.h"
#include <cstdlib>
#include <string>

string Armor::listOfEnchantments[] = {"Armor class"};

Armor::Armor(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Armor") {
    string enchantType = Armor::getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor(int enchantBonus) : Equipment(enchantBonus), name("Armor") {
    string enchantType = Armor::getRandomEnchantment();
    setEnchantment(enchantType);
}
Armor::Armor() : name("Armor"){
    string enchantType = Armor::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Armor::getRandomEnchantment(){
    return listOfEnchantments[0];
}
