#ifndef Item_h
#define Item_h

#include <string>
#include <stdio.h>

using namespace std;

class Item{
private:
    bool equipped;
public:
    explicit Item(bool equippedValue) : equipped(equippedValue){};
    Item() : equipped(false){};

    bool getEquipped() const {return equipped;};
    void setEquipped(bool value){equipped = value;};
    void printItem();// prints the item to the screen
};

#endif