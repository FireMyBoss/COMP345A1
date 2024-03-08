#ifndef Item_h
#define Item_h

#include <string>
#include <stdio.h>

using namespace std;

class Item{
private:
    bool equipped;
protected:
   int enchantmentBonus; //bonus amount, 1-5
   string enchantmentType;  //bonus type (name)
public:
    explicit Item(bool equippedValue) : equipped(equippedValue){};
    Item() : equipped(false){};

    bool getEquipped() const {return equipped;};
    void setEquipped(bool value){equipped = value;};

    string getEnchantment(){return enchantmentType;};
    int getBonus() const {return enchantmentBonus;};
};

#endif