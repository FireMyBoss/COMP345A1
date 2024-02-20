#ifndef Equipment_h
#define Equipment_h

#include <string>
#include <stdio.h>
#include "Item.h"

using namespace std;

class Equipment : public item{
private:
   int enchantmentBonus; //bonus amount, 1-5
   string enchantmentType;  //bonus type (name)
public:
    Equipment(bool equippedValue, int enchantBonus, string enchantType) : item(equippedValue), enchantmentBonus(enchantBonus), enchantmentType(enchantType) {};
    Equipment(bool equippedValue, int enchantBonus) : item(equippedValue), enchantmentBonus(enchantBonus){};
    Equipment(int enchantBonus, string enchantType) : enchantmentBonus(enchantBonus), enchantmentType(enchantType){};
    Equipment(int enchantBonus) : enchantmentBonus(enchantBonus){};
    Equipment() {setRandBonus();};
    ~Equipment();

    int getBonus(){return enchantmentBonus;};
    void setBonus(int bonus){enchantmentBonus = bonus;};
    void setRandBonus(); //if enchantmentType != null, gets a random bonus between 1-5

    string getEnchantment(){return enchantmentType;};
    void setEnchantment(string enchantment){enchantmentType = enchantment;};
    virtual string getRandomEnchantment(){return "";};
   
};


#endif