#ifndef Item_h
#define Item_h

#include <string>
#include <stdio.h>
#include "Observable.h"

using namespace std;

class Item : public Observable{
private:
    bool equipped;
protected:
    void abstractPure() override {};
   int enchantmentBonus; //bonus amount, 1-5
   string enchantmentType;  //bonus type (name)
   string name;
public:
    string itmName;
    explicit Item(bool equippedValue) : equipped(equippedValue){};
    Item() : equipped(false){};

    bool getEquipped() const {return equipped;};
    void setEquipped(bool value){equipped = value;};

    void setEnchantment(string & enchantment){enchantmentType = enchantment;};
    virtual void getRandomEnchantment(){};
    string getEnchantment(){return enchantmentType;};
    int getBonus() const {return enchantmentBonus;};
    void setBonus(int bonus){enchantmentBonus = bonus;};

};

Item* getRandItem();

#endif