#include "Weapon.h"
#include <cstdlib>
#include <string>

string Weapon::listOfEnchantments[] = {"Attack bonus", "Damage bonus"};

Weapon::Weapon(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Weapon") {
    string enchantType = Weapon::getRandomEnchantment();
    setEnchantment(enchantType);
}
Weapon::Weapon(int enchantBonus) : Equipment(enchantBonus), name("Weapon") {
    string enchantType = Weapon::getRandomEnchantment();
    setEnchantment(enchantType);
}
Weapon::Weapon() : name("Weapon"){
    string enchantType = Weapon::getRandomEnchantment();
    setRandBonus();
    setEnchantment(enchantType);
}

string Weapon::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    return listOfEnchantments[rand() % 2];
}
