#include "Weapon.h"
#include <cstdlib>
#include <string>

const static string listOfEnchantments[] = {"Attack bonus", "Damage bonus"};

Weapon::Weapon(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(equippedValue, enchantBonus, enchantType);
}
Weapon::Weapon(int enchantBonus) : Equipment(enchantBonus) {
    string enchantType = getRandomEnchantment();
    Equipment(enchantBonus, enchantType);
}
Weapon::Weapon(){
    string enchantType = getRandomEnchantment();
    setRandBonus();
    Equipment(enchantType);
}

string Weapon::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
