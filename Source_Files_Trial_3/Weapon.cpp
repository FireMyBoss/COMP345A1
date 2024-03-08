#include "Weapon.h"
#include <cstdlib>
#include <string>

string Weapon::listOfEnchantments[] = {"Attack bonus", "Damage bonus"};

Weapon::Weapon(bool equippedValue, int enchantBonus) : Equipment(equippedValue, enchantBonus), name("Weapon") {
    Weapon::getRandomEnchantment();
}
Weapon::Weapon(int enchantBonus) : Equipment(enchantBonus), name("Weapon") {
    Weapon::getRandomEnchantment();
}
Weapon::Weapon() : name("Weapon"){
    Weapon::getRandomEnchantment();
    setRandBonus();
}

void Weapon::getRandomEnchantment(){
    srand((unsigned) time(NULL));
    setEnchantment(listOfEnchantments[rand() % 2]);
}
