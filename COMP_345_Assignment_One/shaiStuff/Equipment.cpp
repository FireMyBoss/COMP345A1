#include "Equipment.h"
#include<cstdlib>
#include <ctime>   



void Equipment::setRandBonus(){
    srand((unsigned) time(NULL));
    enchantmentBonus = rand() % 6;

}

void Equipment::getRandomEnchantment(){
    srand((unsigned) time(NULL));

    string listOfEnchantments1[] = {"Intelligence", "Wisdom", "Armor class"};
    string listOfEnchantments3[] = {"Armor class", "Strength", "Constitution", "Wisdom", "Charismas"};
    string listOfEnchantments4[] = {"Constitution", "Strength"};
    string listOfEnchantments5[] = {"Armor class", "Dexterity"};
    string listOfEnchantments6[] = {"Attack bonus", "Damage bonus"};

    switch (equipmentType){
    case 0://helmet
        enchantmentType = listOfEnchantments1[rand() % 3];
        break;
    case 1://armor
        enchantmentType = "Armor class";
        break;
    case 2://shield
        enchantmentType = "Armor class"; 
        break;
    case 3://ring
        enchantmentType = listOfEnchantments3[rand() % 5];
        break;
    case 4://belt
        enchantmentType = listOfEnchantments4[rand() % 2];
        break;
    case 5://boots
        enchantmentType = listOfEnchantments5[rand() % 2];
        break;
    case 6://weapon
        enchantmentType = listOfEnchantments6[rand() % 2];
        break;
    default:
        break;
    }
}
