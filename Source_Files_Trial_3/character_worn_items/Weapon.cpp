#include "Weapon.h"
#include <cstdlib>
#include <string>

string Weapon::listOfEnchantments[] = {"Attack bonus", "Damage bonus"};

Weapon::Weapon(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Weapon::Weapon(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    setEnchantment(enchantType);
}
Weapon::Weapon(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Weapon::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}