#ifndef Item_h
#define Item_h

#include <string>
#include <stdio.h>

using namespace std;

class Item{
private:
    bool equiped;
public:
    explicit Item(bool equippedValue) : equiped(equippedValue){};
    Item() : equiped(false){};

    bool getEquiped(){return equiped;};
    void setEquiped(bool value){equiped = value;};
};

#endif