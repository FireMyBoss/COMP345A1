#ifndef Item_h
#define Item_h

#include <string>
#include <stdio.h>

using namespace std;

class Item {
private:
    bool equiped;
public:
    Item(bool equippedValue) : equiped(equippedValue) {}
    Item() : equiped(false) {}
    ~Item() {} // Destructor definition

    bool getEquiped() { return equiped; }
    void setEquiped(bool value) { equiped = value; }
};

#endif
