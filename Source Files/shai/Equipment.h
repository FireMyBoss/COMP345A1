#ifndef Equipment_h
#define Equipment_h

#include <string>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Equipment : public Item{
private:
   int enchantmentBonus; //bonus amount, 1-5
   string enchantmentType;  //bonus type (name)
   int equipmentType; //0 = helmet, 1 = armor, 2 = shield, 
                      //3 = ring, 4 = belt, 5 = boots
                      //6 = weapon
public:
    Equipment(bool equippedValue, int enchantBonus, string enchantType, int equipType) : Item(equippedValue), enchantmentBonus(enchantBonus), enchantmentType(enchantType), equipmentType(equipType) {};
    Equipment(bool equippedValue, int equipType) : Item(equippedValue), equipmentType(equipType) {getRandomEnchantment(); setRandBonus(); };
    Equipment(int equipType) : Item(false), equipmentType(equipType) {getRandomEnchantment(); setRandBonus();};
    ~Equipment(){};

    int getBonus(){return enchantmentBonus;};
    void setBonus(int bonus){enchantmentBonus = bonus;};
    void setRandBonus(); //if enchantmentType != null, gets a random bonus between 1-5

    string getEnchantment(){return enchantmentType;};
    void setEnchantment(string enchantment){enchantmentType = enchantment;};
    void getRandomEnchantment();

    int getEquipmentType(){return equipmentType;};
    void setEquipmentType(int equipType){equipmentType = equipType;}
   
};


#endif